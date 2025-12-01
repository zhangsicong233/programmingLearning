#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

std::queue<int> g_queue;
std::condition_variable g_cv;
std::mutex mtx;

void producer() {
  for (int i = 0; i < 10; ++i) {
    {
      std::unique_lock<std::mutex> lock(mtx);
      g_queue.push(i);

      // 通知消费者来取任务
      g_cv.notify_one();

      std::cout << "Producer: " << i << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::microseconds(100));
  }
}

void consumer() {
  while (true) {
    int value;

    {
      std::unique_lock<std::mutex> lock(mtx);

      // 如果队列为空，就要等待
      g_cv.wait(lock, []() { return !g_queue.empty(); });

      value = g_queue.front();
      g_queue.pop();
    }

    std::cout << "Consumer: " << value << std::endl;
  }
}

int main() {
  std::thread t1(producer);
  std::thread t2(consumer);

  t1.join();
  t2.join();

  return 0;
}