add_library(database
        database.h
        database.cpp)

target_include_directories(database PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/primary_key_generator
        ${PROJECT_SOURCE_DIR}/src/table
        ${PROJECT_SOURCE_DIR}/src/exceptions)