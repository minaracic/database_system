cmake_minimum_required(VERSION 3.17)
project(database_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(database_system main.cpp)

add_library(data_types
        src/data_types/data_types.cpp)

add_subdirectory(test)

#enable_testing()

#Testing project
