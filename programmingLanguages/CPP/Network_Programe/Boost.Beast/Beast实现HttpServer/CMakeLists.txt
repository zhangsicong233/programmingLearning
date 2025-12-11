cmake_minimum_required(VERSION 3.10)
project(BeastHttpServer VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找Boost库
find_package(Boost 1.70 REQUIRED COMPONENTS system)
# 查找jsoncpp库
find_package(jsoncpp REQUIRED)

# 添加可执行文件
add_executable(HttpServer HttpServer.cpp)

# 链接库
target_link_libraries(HttpServer
    Boost::boost
    Boost::system
    jsoncpp_lib
)

# 添加包含目录（如果需要）
target_include_directories(HttpServer PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${JSONCPP_INCLUDE_DIRS}
)

# 安装目标（可选）
# install(TARGETS HttpServer DESTINATION bin)