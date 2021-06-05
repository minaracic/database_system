#include "table.h"

Table::Table() {
// TODO: test to see difference between stack and heap allocation
//    ColumnDataInfo* default_pk_ptr = new ColumnDataInfo(new Integer(), "Primary key", true);
//    ColumnDataInfo default_pk = ColumnDataInfo(new Integer(), "Primary key", true);
//    insertColumn(*default_pk_ptr);

    primary_key_generator = new PrimaryKeyGenerator();
    columns_info.push_back(ColumnDataInfo(DataType::INTEGER, "ID", true));
}

Table::Table(std::string table_name): Table(){
    this->table_name = table_name;
}

std::ostream &operator<<(std::ostream &os, const Table &t) {
}

void Table::insertColumnToExistingRows(const ColumnDataInfo &info) {
}

void Table::printTable() const{
    printColumnsInfo();
    printRows();
}

bool Table::insertData(std::vector<DataValue*> data) {
    if(checkIfValidDataToInsert(data)){
        table.push_back(data);
        ids.push_back(primary_key_generator->getNextKey());
        return true;
    }
    return false;
}

bool Table::checkIfValidDataToInsert(const std::vector<DataValue*> data) {
    for(int i=0;i<data.size();i++){
        if(columns_info[i+1].getDataType() != data[i]->getDataType()){
            return false;
        }
    }
    return true;
}

std::string Table::getTableName() const{
    return table_name;
}

Table::Table(PrimaryKeyGenerator* table_name) {

}

void Table::printColumnsInfo() const {
    for(int i=0;i<columns_info.size();i++){
        std::cout << columns_info[i].getFieldName() << '\t';
    }
    std::cout << '\n';
}

void Table::printRows() const {
    for(int i=0;i<table.size();i++){
        std::cout << ids[i] << '\t';

        for(int j=0;j<table[i].size();j++){
            table[i][j]->print();
        }

        std::cout << std::endl;
    }
}

void Table::insertColumn(const ColumnDataInfo &column) {
    columns_info.push_back(column);
}

std::vector<ColumnDataInfo> Table::getColumnsInfo() const {
    return columns_info;
}

std::vector<std::vector<DataValue *>> Table::getTable() const {
    return table;
}

void Table::updateTableName(const std::string &new_name) {
    table_name = new_name;
}
