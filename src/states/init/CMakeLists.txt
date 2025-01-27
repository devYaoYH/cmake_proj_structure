add_library(init_state init.c)

# Specify targets to link compiled binaries
target_link_libraries(init_state PUBLIC print_task)

# Specify directories with relevant header files
target_include_directories(init_state PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/src/common"
  "${PROJECT_SOURCE_DIR}/src/tasks/print"
)
