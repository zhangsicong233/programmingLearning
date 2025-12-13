cmake_minimum_required(VERSION 3.10)
project(BeastWebSocketServer VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找Boost库（需要asio、beast、uuid、system）
find_package(Boost 1.70 REQUIRED COMPONENTS system)

# Boost.Beast是头文件库，不需要链接，但需要asio（依赖于system）
# Boost.UUID也是头文件库
# 我们只需要包含路径

# 添加可执行文件，源文件位于src/目录下
add_executable(WebSocketServer
    src/main.cpp
    src/TCP_WebSocketServer.cpp
    src/Connection.cpp
    src/ConnectionMgr.cpp
)

# 链接库
target_link_libraries(WebSocketServer
    Boost::boost
    Boost::system
)

# 添加包含目录
target_include_directories(WebSocketServer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

# 可选：设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 可选：安装目标
# install(TARGETS WebSocketServer DESTINATION bin)