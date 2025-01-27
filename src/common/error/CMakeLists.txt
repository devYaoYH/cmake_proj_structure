add_library(error error.c)

target_include_directories(error PUBLIC
  "${CMAKE_SOURCE_DIR}/src/common"
)
