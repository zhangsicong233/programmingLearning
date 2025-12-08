cmake_minimum_required(VERSION 3.10)
project(ProtoBufDemo)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Find Protobuf package
find_package(Protobuf REQUIRED)

# Include directories for Protobuf
include_directories(${PROTOBUF_INCLUDE_DIRS})

# Add the proto file
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER msg.proto)

# Add your source files
add_executable(ProtoBufDemo test.cpp ${PROTO_SRC})

# Link protobuf library
target_link_libraries(ProtoBufDemo ${PROTOBUF_LIBRARIES})