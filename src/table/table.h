#pragma once
#include<vector>
#include<string>

#include "primary_key_generator.h"
#include "column_data_info/column_data_info.h"
#include <variant>
//#include "database.h"

class Database;

struct PrintDataValueFn {
    template<typename T>
    void operator()(const T& i) const {
        i.print();
    }
};

class Row {
public:
    Row(int id, std::vector<DataValue> data) : id_{id}, data_{data} {}

    void insert(DataValue value) {
        data_.push_back(value);
    }

    int getId() const {
        return id_;
    }

    const std::vector<DataValue>& getData() const {
        return data_;
    }

    std::vector<DataValue>& getData() {
        return data_;
    }

    void print() const {
        std::cout << id_ << '\t';

        for(int j=0;j<data_.size();j++){
            std::visit(PrintDataValueFn{}, data_[j]);
        }

        std::cout << std::endl;
    }

private:
    int id_;
    std::vector<DataValue> data_;
};

class Table{
    std::string table_name;
    PrimaryKeyGenerator primary_key_generator;

    std::vector<ColumnDataInfo> columns_info;
    std::vector<Row> rows;

    friend class Database;
public:
    Table();
    Table(std::string table_name);
    Table(PrimaryKeyGenerator pk_generator);

    bool insertData(std::vector<DataValue> data);
    // Returns false if add operation is not supported for the given column (e.g. varchar).
    // Otherwise, returns true.
    bool addToColumn(const std::string& column_name, int value);
    void insertColumn(const ColumnDataInfo& column);

    std::string getTableName() const;
    std::vector<ColumnDataInfo> getColumnsInfo() const;
    const std::vector<Row>& getRows() const;

    void printTable() const;
    void printColumnsInfo() const;
    void printRows() const;
    friend std::ostream &operator<<(std::ostream &os, const Table& t);

private:
    void insertColumnToExistingRows(const ColumnDataInfo &info);
    bool checkIfValidDataToInsert(std::vector<DataValue*> data);
    void updateTableName(const std::string& new_name);
};