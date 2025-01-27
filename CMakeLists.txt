cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cmake_example C CXX ASM)

add_subdirectory(src)

include(CTest)

# TODO(yaoyiheng): link to external_dependency