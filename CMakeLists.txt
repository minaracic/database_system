cmake_minimum_required(VERSION 3.17)
project(database_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(database_system main.cpp)

add_library(server
        src/server/server.cpp
        src/database/database.cpp
        src/data_types/data_types.cpp)

target_link_libraries(database_system PRIVATE server)

add_subdirectory(test)

#enable_testing()
