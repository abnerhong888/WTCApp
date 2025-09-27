cmake_minimum_required(VERSION 3.28.0)

# CACHE type "docstring" -> setting global variable

set(CMAKE_CXX_STANDARD 14 CACHE STRING "C++ standard to be used" FORCE)
set(CMAKE_CXX_EXTENSIONS ON CACHE BOOL "c++ extensions to be used" FORCE)
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "c++ standard required" FORCE)
set(CMAKE_CXX_FLAGS "-g -Wall" CACHE STRING "c++ flags" FORCE)
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "build type" FORCE)

#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON CACHE BOOL "windows export all symbols to be used" FORCE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON ON CACHE BOOL "cmake export compile command" FORCE)
set(SOLUTION_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../" CACHE STRING "set solution dir" FORCE)
set(LINKER_DIR "${SOLUTION_DIR}/linker.cmake" CACHE STRING "set linker dir" FORCE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE STRING "set runtime output directory" FORCE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" CACHE STRING "set library output directory" FORCE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" CACHE STRING "set archive output directory" FORCE)