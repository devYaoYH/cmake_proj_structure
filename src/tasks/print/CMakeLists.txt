add_library(print_task print.c)

# Specify directories with relevant header files
target_include_directories(print_task PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${CMAKE_SOURCE_DIR}/src/common"
)

add_subdirectory(test)