#pragma once
#include<vector>
#include<string>

#include "primary_key_generator.h"
#include "column_data_info/column_data_info.h"
//#include "database.h"

class Database;

class Table{
    std::string table_name;
    PrimaryKeyGenerator* primary_key_generator;

    //TODO: make id as part of table
    std::vector<ColumnDataInfo> columns_info;
    std::vector<std::vector<DataValue*>> table;
    std::vector<int> ids;

    friend class Database;
public:
    Table();
    Table(std::string table_name);
    Table(PrimaryKeyGenerator* pk_generator);

    bool insertData(std::vector<DataValue*> data);
    void insertColumn(const ColumnDataInfo& column);

    std::string getTableName() const;
    std::vector<ColumnDataInfo> getColumnsInfo() const;
    std::vector<std::vector<DataValue*>> getTable() const;

    void printTable() const;
    void printColumnsInfo() const;
    void printRows() const;
    friend std::ostream &operator<<(std::ostream &os, const Table& t);

private:
    void insertColumnToExistingRows(const ColumnDataInfo &info);
    bool checkIfValidDataToInsert(std::vector<DataValue*> data);
    void updateTableName(const std::string& new_name);
};