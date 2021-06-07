add_library(database_exceptions INTERFACE)
target_sources(database_exceptions INTERFACE
        not_unique_table_name.h)

#target_compile_options(database_exceptions PUBLIC -fno-exceptions)
