# 源文件分组
set(SERVER_SOURCES
    CServer.cpp
    CSession.cpp
    LogicSystem.cpp
    MsgNode.cpp
)

set(CLIENT_SOURCES
    LogicClient.cpp
)

set(SERVER_MAIN_SOURCE
    LogicServer.cpp
)

# 创建静态库（核心逻辑）
add_library(LogicCore STATIC ${SERVER_SOURCES})
# 链接JsonCpp库和Boost库
target_link_libraries(LogicCore PRIVATE ${JSONCPP_LIBRARIES} ${Boost_LIBRARIES})

# 创建服务器可执行文件
add_executable(LogicServer ${SERVER_MAIN_SOURCE})
target_link_libraries(LogicServer LogicCore ${JSONCPP_LIBRARIES} ${Boost_LIBRARIES})

# 创建客户端可执行文件（如果不需要JsonCpp，可以不加）
add_executable(LogicClient ${CLIENT_SOURCES})
target_link_libraries(LogicClient LogicCore ${Boost_LIBRARIES})

# 如果客户端也需要JsonCpp，取消下面的注释
# target_link_libraries(LogicClient ${JSONCPP_LIBRARIES})

# 设置可执行文件属性
set_target_properties(LogicServer PROPERTIES
    OUTPUT_NAME "logic-server"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin
)

set_target_properties(LogicClient PROPERTIES
    OUTPUT_NAME "logic-client"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin
)