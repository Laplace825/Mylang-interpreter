
file(GLOB_RECURSE THIRD_SRC "${THIRD_PARTY_DIR}/json/*.cpp")
add_library(third STATIC ${THIRD_SRC})