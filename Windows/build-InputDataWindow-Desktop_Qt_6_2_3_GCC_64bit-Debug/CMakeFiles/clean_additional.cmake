# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/InputData_lib_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/InputData_lib_autogen.dir/ParseCache.txt"
  "InputData_lib_autogen"
  )
endif()
