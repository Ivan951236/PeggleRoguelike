cmake_minimum_required(VERSION 3.10)
project(inventory_cli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(inventory_cli main.cpp)