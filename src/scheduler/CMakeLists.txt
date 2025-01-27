add_library(scheduler scheduler.c)
target_link_libraries(scheduler PUBLIC init_state)

target_include_directories(scheduler PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${CMAKE_SOURCE_DIR}/src/common"
  "${CMAKE_SOURCE_DIR}/src/states/init"
)

# Debug message to print the list of include directories for state_machine
get_target_property(INCLUDE_DIRS scheduler INCLUDE_DIRECTORIES)
message("[state_machine] Include directories: ${INCLUDE_DIRS}")
