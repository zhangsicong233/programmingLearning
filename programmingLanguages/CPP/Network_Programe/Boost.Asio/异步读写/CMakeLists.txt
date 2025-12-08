cmake_minimum_required(VERSION 3.10)
project(AsyncNetworkProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找线程库
find_package(Threads REQUIRED)

# 添加可执行文件
add_executable(AsyncServer AsyncServer.cpp CServer.cpp CSession.cpp)
add_executable(AsyncClient AsyncClient.cpp)

# 设置头文件包含目录
target_include_directories(AsyncServer PRIVATE .)
target_include_directories(AsyncClient PRIVATE .)

# 链接线程库
target_link_libraries(AsyncServer Threads::Threads)
target_link_libraries(AsyncClient Threads::Threads)

# 如果CServer和CSession有共同的头文件，确保包含路径正确
# 例如：target_include_directories(AsyncServer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})