cmake_minimum_required(VERSION 3.10)
project(LogicServerProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 查找jsoncpp库
find_package(jsoncpp REQUIRED)

# 包含当前目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 定义所有源文件
set(COMMON_SOURCES
    MsgNode.cpp
)

set(SERVER_SOURCES
    CServer.cpp
    CSession.cpp
    LogicServer.cpp
    ${COMMON_SOURCES}
)

set(CLIENT_SOURCES
    LogicClient.cpp
    ${COMMON_SOURCES}
)

# 添加服务器可执行文件
add_executable(LogicServer ${SERVER_SOURCES})
target_include_directories(LogicServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(LogicServer jsoncpp_lib)

# 添加客户端可执行文件
add_executable(LogicClient ${CLIENT_SOURCES})
target_include_directories(LogicClient PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(LogicClient jsoncpp_lib)

# 可选：如果jsoncpp使用不同的包名，可以尝试以下别名
if(NOT TARGET jsoncpp_lib)
    # 尝试常见的jsoncpp目标名
    if(TARGET jsoncpp)
        add_library(jsoncpp_lib ALIAS jsoncpp)
    elseif(TARGET jsoncpp::jsoncpp)
        add_library(jsoncpp_lib ALIAS jsoncpp::jsoncpp)
    elseif(TARGET JsonCpp::JsonCpp)
        add_library(jsoncpp_lib ALIAS JsonCpp::JsonCpp)
    endif()
endif()

# 设置编译器选项
if(MSVC)
    target_compile_options(LogicServer PRIVATE /W4)
    target_compile_options(LogicClient PRIVATE /W4)
else()
    target_compile_options(LogicServer PRIVATE -Wall -Wextra)
    target_compile_options(LogicClient PRIVATE -Wall -Wextra)
endif()