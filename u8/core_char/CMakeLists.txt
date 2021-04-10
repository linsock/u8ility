# build
add_library(mchar mchar.cpp)
# link
target_link_libraries(mchar utils)
target_include_directories(mchar PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/u8/core_string"
                          "${PROJECT_SOURCE_DIR}/aux"
                          )