add_subdirectory(scheduler)
add_subdirectory(states)
add_subdirectory(tasks)

add_executable(cmake_example main.c)
target_link_libraries(cmake_example PUBLIC scheduler)

# Global include directory common for all targets
target_include_directories(cmake_example PUBLIC 
  "${PROJECT_BINARY_DIR}"
  "${CMAKE_SOURCE_DIR}/src/common"
  "${CMAKE_SOURCE_DIR}/src/scheduler"
)