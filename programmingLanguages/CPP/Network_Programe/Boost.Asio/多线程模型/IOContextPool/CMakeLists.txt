cmake_minimum_required(VERSION 3.10)
project(IOContextPool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find Boost
find_package(Boost 1.83 REQUIRED COMPONENTS system)

# Find jsoncpp
find_package(jsoncpp REQUIRED)

# Enable threading
find_package(Threads REQUIRED)

# Include directories
include_directories(include)

# Source files for server
set(SERVER_SOURCES
    src/server/AsioIOContextPool.cpp
    src/server/CServer.cpp
    src/server/CSession.cpp
    src/server/MsgNode.cpp
    src/server/LogicSystem.cpp
    src/server/LogicServer.cpp
)

# Source files for client
set(CLIENT_SOURCES
    src/client/LogicClient.cpp
)

# Add executables
add_executable(LogicServer ${SERVER_SOURCES})
add_executable(LogicClient ${CLIENT_SOURCES})

# Link libraries
target_link_libraries(LogicServer Boost::system ${JSONCPP_LIBRARIES} Threads::Threads)
target_link_libraries(LogicClient Boost::system ${JSONCPP_LIBRARIES} Threads::Threads)

# Use modern target if available
if(TARGET JsonCpp::JsonCpp)
    target_link_libraries(LogicServer JsonCpp::JsonCpp)
    target_link_libraries(LogicClient JsonCpp::JsonCpp)
elseif(TARGET jsoncpp_lib)
    target_link_libraries(LogicServer jsoncpp_lib)
    target_link_libraries(LogicClient jsoncpp_lib)
endif()

# Set output directory (optional)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)