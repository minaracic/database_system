add_library(table
        table.cpp
        table.h)

target_include_directories(table PUBLIC
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/database
        ${PROJECT_SOURCE_DIR}/src/column_data_info
        ${PROJECT_SOURCE_DIR}/src/data_types
        ${PROJECT_SOURCE_DIR}/src/primary_key_generator)
