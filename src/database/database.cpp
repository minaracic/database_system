#include "database.h"

void Database::insertTable(Table&& to_insert) {
    if(database_tables_by_name.find(to_insert.table_name)!=database_tables_by_name.end()){
        throw NotUniqueTableName();
    }
    database_tables_by_name[to_insert.table_name] = std::move(to_insert);
}

Database::Database(const std::string &name) {
    database_name = name;
}

void Database::setName(const std::string &name) {
    database_name = name;
}

//TODO: implement
bool Database::removeTableByName(const std::string &table_name) {
    return false;
}

void Database::printTablesInfo() const{
    for (const auto& [name, table] : database_tables_by_name) {
        std::cout << name << std::endl;
        table.printTable();
        std::cout << std::endl << std::endl;
    }
}

void Database::changeTableName(const std::string &old_name, const std::string &new_name) {
    Table& table=getTableByNameOrNull(old_name);
    table.updateTableName(new_name);
}

Table& Database::getTableByNameOrNull(const std::string &table_name) {
    return database_tables_by_name.find(table_name)->second;
}
