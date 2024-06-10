
file(GLOB_RECURSE THIRD_LIB_SOURCES "${THIRD_LIB_DIR}/json/*.cpp")
add_library(third_lib STATIC ${THIRD_LIB_SOURCES})