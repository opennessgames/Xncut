# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/XncutPenTool_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/XncutPenTool_autogen.dir/ParseCache.txt"
  "XncutPenTool_autogen"
  )
endif()
