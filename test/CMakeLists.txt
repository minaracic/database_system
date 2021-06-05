include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(database_system_test
        main_test.cpp
        ../src/table/table.cpp
        ../src/column_data_info/column_data_info.cpp
        ../src/data_types/data_types.cpp
        ../src/database/database.cpp
        ../src/primary_key_generator/primary_key_generator.cpp)

#add_dependencies(database_system_test src)

target_include_directories(database_system_test PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/primary_key_generator
        ${PROJECT_SOURCE_DIR}/src/database
        ${PROJECT_SOURCE_DIR}/src/table
        ${PROJECT_SOURCE_DIR}/src/column_data_info
        ${PROJECT_SOURCE_DIR}/src/data_types)

target_link_libraries(database_system_test PUBLIC
        gtest_main)
