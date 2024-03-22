cmake_minimum_required(VERSION 3.22)
project(serialKR)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include(cmake/deps_cpm.cmake)

add_subdirectory(src)