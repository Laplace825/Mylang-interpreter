cmake_minimum_required(VERSION 3.28)
project(interpreter)

set(CMAKE_CXX_STANDARD 26)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 第三方库目录
set(THIRD_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_lib)

# 头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

# 第三方库文件目录
include_directories(${THIRD_LIB_DIR})

file(GLOB_RECURSE SOURCES "token/*.cpp" "lexer/lexer.cpp")

# 用于构建静态库
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/AST_Tree)
add_subdirectory(${THIRD_LIB_DIR})

add_executable(interpreter
        ${SOURCES}
        main.cpp
)

# 链接库
target_link_libraries(interpreter AST_Tree)
target_link_libraries(interpreter third_lib)