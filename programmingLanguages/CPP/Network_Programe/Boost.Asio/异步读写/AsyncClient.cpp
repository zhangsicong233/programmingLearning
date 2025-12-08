// AsyncClient.cpp - 异步读写版本
#include <atomic>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

constexpr int MAX_LENGTH = 1024 * 2;
constexpr int HEAD_LENGTH = 2;

class AsyncClient {
 public:
  AsyncClient(boost::asio::io_context& io_context, const std::string& host,
              int port)
      : io_context_(io_context),
        socket_(io_context),
        resolver_(io_context),
        is_connected_(false),
        is_writing_(false),
        is_reading_(false) {
    // 解析主机名和端口
    tcp::resolver::query query(host, std::to_string(port));
    resolver_.async_resolve(query,
                            boost::bind(&AsyncClient::on_resolve, this,
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::results));
  }

  // 发送消息的接口
  void send_message(const std::string& message) {
    // 将消息放入发送队列
    std::shared_ptr<std::string> msg_ptr =
        std::make_shared<std::string>(message);

    {
      std::lock_guard<std::mutex> lock(send_queue_mutex_);
      send_queue_.push(msg_ptr);
    }

    // 如果没有正在发送的消息，开始发送
    if (!is_writing_) {
      start_send();
    }
  }

  // 关闭连接
  void close() {
    if (socket_.is_open()) {
      socket_.close();
    }
    is_connected_ = false;
  }

 private:
  using tcp = boost::asio::ip::tcp;

  boost::asio::io_context& io_context_;
  tcp::socket socket_;
  tcp::resolver resolver_;

  // 状态标志
  std::atomic<bool> is_connected_;
  std::atomic<bool> is_writing_;
  std::atomic<bool> is_reading_;

  // 发送队列
  std::queue<std::shared_ptr<std::string>> send_queue_;
  std::mutex send_queue_mutex_;

  // 接收缓冲区
  struct ReceiveBuffer {
    char header[HEAD_LENGTH];
    char body[MAX_LENGTH];
    int body_length;

    ReceiveBuffer() : body_length(0) {
      memset(header, 0, sizeof(header));
      memset(body, 0, sizeof(body));
    }
  };

  std::shared_ptr<ReceiveBuffer> recv_buffer_;

  // 解析主机名回调
  void on_resolve(const boost::system::error_code& error,
                  tcp::resolver::results_type endpoints) {
    if (!error) {
      // 异步连接
      boost::asio::async_connect(socket_, endpoints,
                                 boost::bind(&AsyncClient::on_connect, this,
                                             boost::asio::placeholders::error));
    } else {
      std::cerr << "Resolve error: " << error.message() << std::endl;
    }
  }

  // 连接回调
  void on_connect(const boost::system::error_code& error) {
    if (!error) {
      is_connected_ = true;
      std::cout << "Connected to server!" << std::endl;

      // 开始异步接收
      start_receive();

      // 发送欢迎消息
      send_message("Hello from async client!");
    } else {
      std::cerr << "Connect error: " << error.message() << std::endl;
    }
  }

  // 开始发送消息
  void start_send() {
    if (!is_connected_) {
      std::cerr << "Cannot send: not connected" << std::endl;
      return;
    }

    std::lock_guard<std::mutex> lock(send_queue_mutex_);
    if (send_queue_.empty()) {
      is_writing_ = false;
      return;
    }

    is_writing_ = true;
    auto message = send_queue_.front();
    send_queue_.pop();

    // 构建消息：2字节长度 + 消息体
    std::shared_ptr<std::vector<char>> buffer =
        std::make_shared<std::vector<char>>();

    // 添加消息长度（网络字节序）
    short msg_len = static_cast<short>(message->size());
    msg_len = boost::asio::detail::socket_ops::host_to_network_short(msg_len);

    buffer->resize(HEAD_LENGTH + message->size());
    memcpy(buffer->data(), &msg_len, HEAD_LENGTH);
    memcpy(buffer->data() + HEAD_LENGTH, message->c_str(), message->size());

    std::cout << "Async sending: " << *message << std::endl;

    // 异步发送
    boost::asio::async_write(
        socket_, boost::asio::buffer(buffer->data(), buffer->size()),
        boost::bind(&AsyncClient::on_write, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred, buffer));
  }

  // 发送完成回调
  void on_write(const boost::system::error_code& error,
                size_t bytes_transferred,
                std::shared_ptr<std::vector<char>> buffer) {
    if (!error) {
      std::cout << "Async write completed: " << bytes_transferred << " bytes"
                << std::endl;

      // 继续发送队列中的下一条消息
      is_writing_ = false;
      start_send();
    } else {
      std::cerr << "Async write error: " << error.message() << std::endl;
      is_connected_ = false;
    }
  }

  // 开始接收消息
  void start_receive() {
    if (!is_connected_) return;

    is_reading_ = true;
    recv_buffer_ = std::make_shared<ReceiveBuffer>();

    // 异步读取消息头（2字节长度）
    boost::asio::async_read(
        socket_, boost::asio::buffer(recv_buffer_->header, HEAD_LENGTH),
        boost::bind(&AsyncClient::on_read_header, this,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
  }

  // 读取消息头回调
  void on_read_header(const boost::system::error_code& error,
                      size_t bytes_transferred) {
    if (!error && bytes_transferred == HEAD_LENGTH) {
      // 解析消息长度
      short msg_len = 0;
      memcpy(&msg_len, recv_buffer_->header, HEAD_LENGTH);
      msg_len = boost::asio::detail::socket_ops::network_to_host_short(msg_len);

      if (msg_len > 0 && msg_len <= MAX_LENGTH) {
        recv_buffer_->body_length = msg_len;

        // 异步读取消息体
        boost::asio::async_read(
            socket_, boost::asio::buffer(recv_buffer_->body, msg_len),
            boost::bind(&AsyncClient::on_read_body, this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
      } else {
        std::cerr << "Invalid message length: " << msg_len << std::endl;
        start_receive();  // 重新开始接收
      }
    } else {
      if (error == boost::asio::error::eof) {
        std::cout << "Connection closed by server" << std::endl;
      } else if (error) {
        std::cerr << "Async read header error: " << error.message()
                  << std::endl;
      }
      is_connected_ = false;
    }
  }

  // 读取消息体回调
  void on_read_body(const boost::system::error_code& error,
                    size_t bytes_transferred) {
    if (!error && bytes_transferred == recv_buffer_->body_length) {
      // 添加字符串结束符并显示
      recv_buffer_->body[recv_buffer_->body_length] = '\0';
      std::cout << "Async received: " << recv_buffer_->body << " ("
                << bytes_transferred << " bytes)" << std::endl;

      // 继续接收下一条消息
      start_receive();
    } else {
      if (error) {
        std::cerr << "Async read body error: " << error.message() << std::endl;
      } else {
        std::cerr << "Incomplete message: expected "
                  << recv_buffer_->body_length << ", got " << bytes_transferred
                  << " bytes" << std::endl;
      }
      is_connected_ = false;
    }
  }
};

int main() {
  try {
    // 创建IO上下文
    boost::asio::io_context io_context;

    // 创建异步客户端
    AsyncClient client(io_context, "127.0.0.1", 10086);

    // 启动IO上下文处理线程
    std::thread io_thread([&io_context]() {
      try {
        io_context.run();
      } catch (std::exception& e) {
        std::cerr << "IO context error: " << e.what() << std::endl;
      }
    });

    // 主线程处理用户输入
    std::cout << "Async client started. Type messages to send, 'quit' to exit."
              << std::endl;

    std::string input;
    while (std::getline(std::cin, input)) {
      if (input == "quit" || input == "exit") {
        break;
      }

      if (!input.empty()) {
        client.send_message(input);
      }

      std::cout << "> ";
    }

    // 清理
    client.close();
    io_context.stop();
    if (io_thread.joinable()) {
      io_thread.join();
    }

    std::cout << "Client shutdown complete." << std::endl;

  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}