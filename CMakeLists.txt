cmake_minimum_required(VERSION 3.3)
project(arduino_modules)

set(CMAKE_CONFIGURATION_TYPES "CustomType1;CustomType2" CACHE STRING "" FORCE)

set(${CNAME_PROJECT_NAME}_SKETCH sender.ino)