# build
add_library(mstr mstr.cpp)
# link
target_link_libraries(mstr utils)
target_link_libraries(mstr mchar)
target_include_directories(mchar PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/u8/core_char"
                          "${PROJECT_SOURCE_DIR}/aux"
                          )