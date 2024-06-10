cmake_minimum_required(VERSION 3.28)
project(interpreter)

set(CMAKE_CXX_STANDARD 26)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


include_directories(./)
include_directories(./third_lib/)
set(THIRD_LIB_DIR ${PROJECT_SOURCE_DIR}/third_lib)

file(GLOB_RECURSE SOURCES "token/*.cpp" "lexer/lexer.cpp" "${THIRD_LIB_DIR}/json/*.cpp")

add_executable(interpreter ${SOURCES} main.cpp)

