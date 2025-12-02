cmake_minimum_required(VERSION 3.10)
project(AsyncLogger VERSION 1.0.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 线程库
find_package(Threads REQUIRED)

# 源文件
set(ASYNC_LOGGER_SOURCES
    src/ThreadPool.cpp
    src/Logger.cpp
)

# 创建 AsyncLogger 库
add_library(AsyncLogger ${ASYNC_LOGGER_SOURCES})

# 关键：确保头文件路径被所有链接此库的 target 自动继承
target_include_directories(AsyncLogger
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 链接线程库
target_link_libraries(AsyncLogger PUBLIC Threads::Threads)

# 安装规则（可选）
install(TARGETS AsyncLogger
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)

# =======================
# 示例程序（examples/main.cpp）
# =======================
add_executable(main_program examples/main.cpp)
target_link_libraries(main_program PRIVATE AsyncLogger Threads::Threads)

# 启用测试
enable_testing()

# 打印信息
message(STATUS "AsyncLogger version ${AsyncLogger_VERSION}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Threads library: ${CMAKE_THREAD_LIBS_INIT}")