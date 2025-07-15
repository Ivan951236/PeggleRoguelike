cmake_minimum_required(VERSION 3.10)
project(inventory_gtkmm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(inventory_gtkmm main.cpp)
target_compile_options(inventory_gtkmm PRIVATE ${GTKMM_CFLAGS_OTHER})
target_include_directories(inventory_gtkmm PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_libraries(inventory_gtkmm PRIVATE ${GTKMM_LIBRARIES})