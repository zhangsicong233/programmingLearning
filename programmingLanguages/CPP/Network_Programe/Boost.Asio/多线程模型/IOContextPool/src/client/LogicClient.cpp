#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>

#include <atomic>
#include <boost/asio.hpp>
#include <chrono>
#include <cmath>
#include <csignal>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
using namespace boost::asio::ip;

const int MAX_LENGTH = 1024 * 2;
const int HEAD_LENGTH = 2;
const int HEAD_TOTAL = 4;

// Configuration
const int TOTAL_REQUESTS = 500000;
const int MAX_THREADS = 100;  // limit to avoid excessive threading

std::atomic<long long> total_microseconds{0};
std::atomic<int> total_requests{0};
std::atomic<int> failed_requests{0};

void client_thread(int thread_id, int requests_per_thread) {
  try {
    boost::asio::io_context ioc;
    tcp::endpoint remote_ep(address::from_string("127.0.0.1"), 10086);
    tcp::socket sock(ioc);
    boost::system::error_code error = boost::asio::error::host_not_found;
    sock.connect(remote_ep, error);
    if (error) {
      cout << "Thread " << thread_id << " connect failed, code is "
           << error.value() << " error msg is " << error.message() << endl;
      failed_requests += requests_per_thread;
      return;
    }

    for (int i = 0; i < requests_per_thread; ++i) {
      auto req_start = std::chrono::high_resolution_clock::now();

      Json::Value root;
      root["id"] = 1001;
      root["data"] = "hello world";
      std::string request = root.toStyledString();
      size_t request_length = request.length();

      char send_data[MAX_LENGTH] = {0};
      int msgid = 1001;
      int msgid_host =
          boost::asio::detail::socket_ops::host_to_network_short(msgid);
      memcpy(send_data, &msgid_host, 2);

      int request_host_length =
          boost::asio::detail::socket_ops::host_to_network_short(
              request_length);
      memcpy(send_data + 2, &request_host_length, 2);
      memcpy(send_data + 4, request.c_str(), request_length);
      boost::asio::write(sock,
                         boost::asio::buffer(send_data, request_length + 4));

      char reply_head[HEAD_TOTAL];
      size_t reply_length =
          boost::asio::read(sock, boost::asio::buffer(reply_head, HEAD_TOTAL));

      msgid = 0;
      memcpy(&msgid, reply_head, HEAD_LENGTH);
      short msglen = 0;
      memcpy(&msglen, reply_head + 2, HEAD_LENGTH);
      msglen = boost::asio::detail::socket_ops::network_to_host_short(msglen);
      msgid = boost::asio::detail::socket_ops::network_to_host_short(msgid);
      char msg[MAX_LENGTH] = {0};
      size_t msg_length =
          boost::asio::read(sock, boost::asio::buffer(msg, msglen));
      Json::Reader reader;
      reader.parse(std::string(msg, msg_length), root);
      // Optional: print first few messages of first thread
      if (thread_id == 0 && i < 2) {
        std::cout << "msg id is " << root["id"] << " msg is " << root["data"]
                  << endl;
      }

      auto req_end = std::chrono::high_resolution_clock::now();
      auto req_duration = std::chrono::duration_cast<std::chrono::microseconds>(
          req_end - req_start);
      total_microseconds += req_duration.count();
      total_requests++;
    }
  } catch (std::exception& e) {
    std::cerr << "Exception in thread " << thread_id << ": " << e.what()
              << std::endl;
    failed_requests += requests_per_thread;
  }
}

void send_shutdown_signal() {
  // Send SIGINT to LogicServer process
  int ret = std::system("pkill -INT LogicServer");
  if (ret == 0) {
    std::cout << "Shutdown signal sent to server." << std::endl;
  } else {
    std::cerr
        << "Failed to send shutdown signal (maybe server already stopped)."
        << std::endl;
  }
}

int main() {
  auto start = std::chrono::high_resolution_clock::now();

  // Determine number of threads
  unsigned int hw_threads = std::thread::hardware_concurrency();
  if (hw_threads == 0) hw_threads = 4;
  int num_threads = std::min(static_cast<int>(hw_threads * 2), MAX_THREADS);
  num_threads = std::min(num_threads, TOTAL_REQUESTS);
  if (num_threads < 1) num_threads = 1;

  int requests_per_thread = TOTAL_REQUESTS / num_threads;
  int remaining = TOTAL_REQUESTS % num_threads;

  std::cout << "========== Client Configuration ==========" << std::endl;
  std::cout << "Total requests: " << TOTAL_REQUESTS << std::endl;
  std::cout << "Number of threads: " << num_threads << std::endl;
  std::cout << "Requests per thread: " << requests_per_thread << std::endl;
  if (remaining > 0) {
    std::cout << "One extra thread will handle " << remaining
              << " additional requests." << std::endl;
  }
  std::cout << "==========================================" << std::endl;

  std::vector<std::thread> threads;
  threads.reserve(num_threads);

  // Launch threads
  for (int i = 0; i < num_threads; ++i) {
    int extra = (i == 0 ? remaining : 0);  // give extra to first thread
    threads.emplace_back(client_thread, i, requests_per_thread + extra);
  }

  // Wait for all threads
  for (auto& t : threads) {
    t.join();
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto total_duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  std::cout << "\n========== Time Measurement ==========" << std::endl;
  std::cout << "Total wall-clock time: " << total_duration.count()
            << " microseconds (" << total_duration.count() / 1000000.0
            << " seconds)" << std::endl;
  std::cout << "Total requests sent: " << total_requests << std::endl;
  std::cout << "Failed requests: " << failed_requests << std::endl;
  if (total_requests > 0) {
    double avg_us = static_cast<double>(total_microseconds) / total_requests;
    std::cout << "Average per request: " << avg_us << " microseconds"
              << std::endl;
    std::cout << "Average wall-clock per request: "
              << static_cast<double>(total_duration.count()) / total_requests
              << " microseconds" << std::endl;
    std::cout << "Throughput: "
              << (total_requests / (total_duration.count() / 1000000.0))
              << " requests/sec" << std::endl;
  }
  std::cout << "======================================\n" << std::endl;

  // Gracefully shutdown server
  std::cout << "Initiating server shutdown..." << std::endl;
  send_shutdown_signal();

  return 0;
}