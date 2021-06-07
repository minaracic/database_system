#include "database.h"

void Database::insertTable(Table *to_insert) throw(NotUniqueTableName) {
    if(database_tables_by_name.find(to_insert->table_name)!=database_tables_by_name.end()){
        throw NotUniqueTableName();
    }
    database_tables_by_name[to_insert->table_name] = to_insert;
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
    for(auto it=database_tables_by_name.begin();it!=database_tables_by_name.end();++it){
        std::cout << it->second->table_name << std::endl;
        it->second->printTable();
        std::cout << std::endl << std::endl;
    }
}

bool Database::updateTableName(const std::string &old_name, const std::string &new_name) {
//    if(database_tables_by_name.find()){
//        changeTableName(old_name, new_name);
//        return true;
//    }
//    return false;
}

void Database::changeTableName(const std::string &old_name, const std::string &new_name) {
    Table* table=getTableByNameOrNull(old_name);
    table->updateTableName(new_name);
}

Table *Database::getTableByNameOrNull(const std::string &table_name) {
    return database_tables_by_name.find(table_name)->second;
}
