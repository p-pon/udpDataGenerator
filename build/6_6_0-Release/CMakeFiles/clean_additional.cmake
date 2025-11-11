# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\UdpGeneratorGUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\UdpGeneratorGUI_autogen.dir\\ParseCache.txt"
  "UdpGeneratorGUI_autogen"
  )
endif()
