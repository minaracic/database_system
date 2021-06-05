#include "database.h"

bool Database::checkTableNameUniqueAndInsertTable(Table* to_insert) {
    if(isTableNameUnique(to_insert->getTableName())){
        database_tables.push_back(to_insert);
        return true;
    }
    return false;
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

bool Database::isTableNameUnique(const std::string &name) {
    for(int i=0;i<database_tables.size();i++){
        if(database_tables[i]->getTableName() == name)return false;
    }
    return true;
}

void Database::printTablesInfo() const{
    for(int i=0;i<database_tables.size();i++){
        std::cout << database_tables[i]->getTableName() << std::endl;
        database_tables[i]->printTable();
        std::cout << std::endl << std::endl;
    }
}

bool Database::updateTableName(const std::string &old_name, const std::string &new_name) {
    if(isTableNameUnique(new_name)){
        changeTableName(old_name, new_name);
        return true;
    }
    return false;
}

void Database::changeTableName(const std::string &old_name, const std::string &new_name) {
    Table* table=getTableByNameOrNull(old_name);
    table->updateTableName(new_name);
}

Table *Database::getTableByNameOrNull(const std::string &table_name) {
    for(int i=0;i<database_tables.size();i++){
        if(database_tables[i]->getTableName() == table_name)
            return database_tables[i];
    }
    return nullptr;
}
