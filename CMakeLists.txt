cmake_minimum_required(VERSION 3.28)
project(static_vector_project VERSION 0.0 LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -Werror -fsanitize=address,undefined -g)
    add_link_options(-fsanitize=address,undefined)
endif ()

add_library(static_vector static_vector.cpp)
add_subdirectory(tests)
