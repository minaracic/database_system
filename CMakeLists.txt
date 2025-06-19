cmake_minimum_required(VERSION 3.17)
project(database_system)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(src/data_types)
add_subdirectory(test)
#add_subdirectory(src/primary_key_generator)
#add_subdirectory(src/database)
#add_subdirectory(src/table)
#add_subdirectory(src/column_data_info)
#add_subdirectory(src/exceptions)

add_executable(database_system main.cpp)

target_include_directories(database_system PUBLIC
        src/data_types)

target_link_libraries(database_system PUBLIC
        src)

enable_testing()