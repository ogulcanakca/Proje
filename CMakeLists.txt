cmake_minimum_required(VERSION 3.22)
project(Proje)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Proje)

add_executable(Proje
        Proje/Proje.cpp)
