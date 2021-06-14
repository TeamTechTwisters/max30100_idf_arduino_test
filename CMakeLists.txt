# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(main)
#include_directories(max30100)
#add_executable(MyExec
#  max30100/MAX30100_BeatDetector.cpp
#  max30100/MAX30100_BeatDetector.h
#  max30100/CircularBuffer.h
#  max30100/MAX30100_Filters.h
#  max30100/MAX30100_PulseOximeter.cpp
#  max30100/MAX30100_PulseOximeter.h
#  max30100/MAX30100_Registers.h
#  max30100/MAX30100_SpO2Calculator.cpp
#  max30100/MAX30100_SpO2Calculator.h
#  max30100/MAX30100.cpp
#)
#include(${CMAKE_CURRENT_SOURCE_DIR}/components/arduino/CMakeLists.txt)

