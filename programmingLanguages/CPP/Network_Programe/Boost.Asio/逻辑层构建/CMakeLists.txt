cmake_minimum_required(VERSION 3.10)
project(LogicLayer VERSION 1.0.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 包含目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 查找JsonCpp库
find_package(PkgConfig)
pkg_check_modules(JSONCPP jsoncpp)

if(JSONCPP_FOUND)
    include_directories(${JSONCPP_INCLUDE_DIRS})
    link_directories(${JSONCPP_LIBRARY_DIRS})
    set(JSONCPP_LIBRARIES ${JSONCPP_LIBRARIES})
    message(STATUS "Found JsonCpp: ${JSONCPP_INCLUDE_DIRS}")
else()
    # 尝试使用find_package
    find_package(jsoncpp REQUIRED)
    if(jsoncpp_FOUND)
        set(JSONCPP_LIBRARIES jsoncpp)
        message(STATUS "Found JsonCpp via find_package")
    else()
        # 如果都找不到，尝试手动查找
        find_path(JSONCPP_INCLUDE_DIR json/json.h
            PATHS /usr/include /usr/local/include /opt/local/include
            PATH_SUFFIXES jsoncpp)
        
        find_library(JSONCPP_LIBRARY 
            NAMES jsoncpp
            PATHS /usr/lib /usr/local/lib /opt/local/lib)
        
        if(JSONCPP_INCLUDE_DIR AND JSONCPP_LIBRARY)
            include_directories(${JSONCPP_INCLUDE_DIR})
            set(JSONCPP_LIBRARIES ${JSONCPP_LIBRARY})
            message(STATUS "Found JsonCpp manually: ${JSONCPP_LIBRARY}")
        else()
            message(FATAL_ERROR "JsonCpp library not found. Please install libjsoncpp-dev")
        endif()
    endif()
endif()

# 查找Boost库
find_package(Boost REQUIRED COMPONENTS system thread)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "Found Boost: ${Boost_VERSION}")
else()
    message(FATAL_ERROR "Boost library not found. Please install libboost-dev")
endif()

# 添加子目录
add_subdirectory(src)