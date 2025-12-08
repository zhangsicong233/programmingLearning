cmake_minimum_required(VERSION 3.10)
project(JsonCppDemo)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 添加 jsoncpp 头文件路径
include_directories(/usr/include/jsoncpp)

# 查找 jsoncpp 库
find_package(jsoncpp REQUIRED)

# 添加源文件
add_executable(test test.cpp)

# 链接 jsoncpp 库
target_link_libraries(test jsoncpp)