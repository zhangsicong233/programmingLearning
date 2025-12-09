cmake_minimum_required(VERSION 3.10)
project(IOThreadPool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find Boost components
find_package(Boost 1.66 REQUIRED COMPONENTS system thread)

# Find jsoncpp
find_package(jsoncpp REQUIRED)

# Source files for the common library
set(COMMON_SOURCES
    src/AsioThreadPool.cpp
    src/CServer.cpp
    src/CSession.cpp
    src/LogicSystem.cpp
    src/MsgNode.cpp
)

# Create static library
add_library(iothreadpool STATIC ${COMMON_SOURCES})

# Include directories for the library
target_include_directories(iothreadpool PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
    ${JSONCPP_INCLUDE_DIRS}
)

# Link libraries to the common library
target_link_libraries(iothreadpool PUBLIC
    Boost::system
    Boost::thread
    jsoncpp_lib
)

# Server executable
add_executable(server apps/server/Service_main.cpp)
target_link_libraries(server iothreadpool)

# Client executable
add_executable(client apps/client/Client_main.cpp)
target_link_libraries(client iothreadpool)

# Install targets (optional)
# install(TARGETS server client DESTINATION bin)