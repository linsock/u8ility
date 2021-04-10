
cmake_minimum_required(VERSION 3.10)

project(u8ility VERSION 1.0)

# set cxx standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include submodules
add_subdirectory(aux)
add_subdirectory(u8)

add_executable(u8ility main.cpp)

# link built submodules
target_link_libraries(u8ility PUBLIC mstr mchar utils)
target_include_directories(u8ility PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/u8/core_string"
                          "${PROJECT_SOURCE_DIR}/u8/core_char"
                          "${PROJECT_SOURCE_DIR}/aux"
                          )