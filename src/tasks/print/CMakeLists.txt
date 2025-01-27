add_library(print_task print.c)

# Specify targets to link compiled binaries
target_link_libraries(print_task PUBLIC error)

# Specify directories with relevant header files
target_include_directories(print_task PUBLIC
  "${CMAKE_SOURCE_DIR}/src/common"
)

add_subdirectory(test)