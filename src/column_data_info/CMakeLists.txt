add_library(column_data_info
        column_data_info.cpp
        column_data_info.h)

target_include_directories(column_data_info PUBLIC
        ${PROJECT_SOURCE_DIR}/src/data_types)
