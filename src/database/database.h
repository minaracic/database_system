#pragma once
#include <string>
#include <vector>

#include "table.h"

class Database{
    std::string database_name;
    std::vector<Table*> database_tables;

public:
    Database(const std::string& name);

    void setName(const std::string& name);

    bool checkTableNameUniqueAndInsertTable(Table* to_insert);
    bool removeTableByName(const std::string& table_name);
    bool updateTableName(const std::string& old_name, const std::string& new_name);
    Table* getTableByNameOrNull(const std::string& table_name);

    void printTablesInfo() const;

private:
    bool isTableNameUnique(const std::string& name);
    void changeTableName(const std::string& old_name, const std::string& new_name);
};