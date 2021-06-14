#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "table.h"
#include "exceptions/not_unique_table_name.h"

class Database{
    std::string database_name;
//    std::vector<Table*> database_tables;
    std::unordered_map<std::string, Table> database_tables_by_name;

public:
    Database(const std::string& name);

    void setName(const std::string& name);

    void insertTable(Table&& to_insert);
    bool removeTableByName(const std::string& table_name);
    Table& getTableByNameOrNull(const std::string& table_name);
    void changeTableName(const std::string& old_name, const std::string& new_name);

    void printTablesInfo() const;

private:
};