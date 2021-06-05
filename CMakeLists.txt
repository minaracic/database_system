cmake_minimum_required(VERSION 3.17)
project(database_system)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(src/primary_key_generator)
add_subdirectory(src/database)
add_subdirectory(src/table)
add_subdirectory(src/column_data_info)
add_subdirectory(src/data_types)
add_subdirectory(test)

add_executable(database_system main.cpp)

target_include_directories(database_system PUBLIC
        src
        src/primary_key_generator
        src/database
        src/table
        src/data_types
        src/column_data_info)

target_link_libraries(database_system PUBLIC
        src)

