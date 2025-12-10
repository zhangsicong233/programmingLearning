cmake_minimum_required(VERSION 3.10)
project(AsyncServer CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find PkgConfig
find_package(PkgConfig REQUIRED)

# Find Boost components
find_package(Boost 1.83 REQUIRED COMPONENTS system thread)

# Find JsonCpp via pkg-config
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

# Include directories
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${JSONCPP_INCLUDE_DIRS})
include_directories(include)

# Add definitions for Boost.Asio coroutines
add_definitions(-DBOOST_ASIO_HAS_CO_AWAIT)
add_definitions(-DBOOST_ASIO_HAS_STD_COROUTINE)

# Source files for server
set(SERVER_SOURCES
    src/server/AsioIOContextPool.cpp
    src/server/CServer.cpp
    src/server/CSession.cpp
    src/server/LogicSystem.cpp
    src/server/MsgNode.cpp
    src/server/CoroutineServer.cpp
)

# Source files for client
set(CLIENT_SOURCES
    src/client/TestClient.cpp
)

# Add executables
add_executable(server ${SERVER_SOURCES})
add_executable(client ${CLIENT_SOURCES})

# Link libraries
target_link_libraries(server ${Boost_LIBRARIES} ${JSONCPP_LIBRARIES} pthread)
target_link_libraries(client ${Boost_LIBRARIES} ${JSONCPP_LIBRARIES} pthread)

# Set properties for Boost
target_include_directories(server PRIVATE ${Boost_INCLUDE_DIRS} include)
target_include_directories(client PRIVATE ${Boost_INCLUDE_DIRS} include)

# Install (optional)
# install(TARGETS server client RUNTIME DESTINATION bin)