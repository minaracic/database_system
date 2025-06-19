project(database_system)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(database_system_test
        data_types_test.cpp)

target_include_directories(database_system_test PUBLIC
        ${PROJECT_SOURCE_DIR}/src
#        ${PROJECT_SOURCE_DIR}/src/primary_key_generator
#        ${PROJECT_SOURCE_DIR}/src/database
#        ${PROJECT_SOURCE_DIR}/src/table
#        ${PROJECT_SOURCE_DIR}/src/column_data_info
        ${PROJECT_SOURCE_DIR}/src/data_types)

target_link_libraries(database_system_test PUBLIC
        gtest_main
        src)