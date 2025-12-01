#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

class ThreadPool {
 public:
  ThreadPool(int numThreads) : _stop(false) {
    for (int i = 0; i < numThreads; ++i) {
      _threads.emplace_back([this]() {
        while (true) {
          std::function<void()> task;

          {
            std::unique_lock<std::mutex> lock(_mtx);
            _condition.wait(lock,
                            [this]() { return _stop || !_tasks.empty(); });

            if (_stop && _tasks.empty()) {
              return;
            }

            task = std::move(_tasks.front());
            _tasks.pop();
          }

          task();
        }
      });
    }
  }

  ~ThreadPool() {
    {
      std::unique_lock<std::mutex> lock(_mtx);
      _stop = true;
    }

    _condition.notify_all();
    for (auto& t : _threads) {
      t.join();
    }
  }

  template <typename F, typename... Args>
  void enQueue(F&& f, Args&&... args) {
    auto task = [func = std::forward<F>(f),
                 ... args = std::forward<Args>(args)]() mutable {
      func(std::forward<Args>(args)...);
    };

    {
      std::unique_lock<std::mutex> lock(_mtx);
      _tasks.emplace(std::move(task));
    }

    _condition.notify_one();
  }

 private:
  std::vector<std::thread> _threads;
  std::queue<std::function<void()>> _tasks;

  std::mutex _mtx;
  std::condition_variable _condition;

  bool _stop;
};

int main() {
  ThreadPool pool(4);

  for (int i = 0; i < 10; ++i) {
    pool.enQueue([i]() {
      std::cout << "task: " << i << " is running" << std::endl;

      std::this_thread::sleep_for(std::chrono::seconds(1));

      std::cout << "task: " << i << " is done" << std::endl;
    });
  }

  return 0;
}