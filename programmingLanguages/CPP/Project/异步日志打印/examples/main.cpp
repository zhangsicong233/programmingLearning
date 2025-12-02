/**
 * @file main.cpp
 * @brief 异步日志器使用示例（基于线程池）
 *
 * 演示如何使用异步日志器记录格式化日志。
 * 日志文件将保存为 "log.txt"。
 */

#include <chrono>
#include <iostream>
#include <thread>

#include "AsyncLogger/Logger.h"

int main() {
  try {
    // 使用异步日志器（线程池）
    auto logger = Logger::create("log.txt");

    logger->log("Starting application.");

    int user_id = 42;
    std::string action = "login";
    double duration = 3.5;
    std::string world = "World";

    logger->log("User {} performed {} in {} seconds.", user_id, action,
                duration);
    logger->log("Hello {}", world);
    logger->log("This is a message without placeholders.", 1);
    logger->log("Multiple placeholders: {}, {}, {}, {}.", 1, 2, 3);

    // 模拟一些延迟以确保后台线程处理完日志
    std::this_thread::sleep_for(std::chrono::seconds(1));
  } catch (const std::exception& ex) {
    std::cerr << "日志系统初始化失败: " << ex.what() << std::endl;

    return 1;
  }

  return 0;
}