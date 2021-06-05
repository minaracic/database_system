#add_library(src
#        table)

add_library(src INTERFACE)
target_link_libraries(src INTERFACE
        table
        data_types
        database
        primary_key_generator
        column_data_info)

#target_include_directories(src PUBLIC
#        primary_key_generator
#        table
#        database)
