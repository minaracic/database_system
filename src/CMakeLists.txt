add_library(src INTERFACE)
target_link_libraries(src INTERFACE
        table
        data_types
        database
        primary_key_generator
        column_data_info)
