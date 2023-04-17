cmake_minimum_required (VERSION 3.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "Debug")
project (exampleProject)
add_subdirectory (src) 
enable_testing ()

