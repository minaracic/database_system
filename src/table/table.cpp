#include "table.h"

#include <utility>

Table::Table() {
// TODO: test to see difference between stack and heap allocation
//    ColumnDataInfo* default_pk_ptr = new ColumnDataInfo(new INT(), "Primary key", true);
//    ColumnDataInfo default_pk = ColumnDataInfo(new INT(), "Primary key", true);
//    insertColumn(*default_pk_ptr);

    columns_info.push_back(ColumnDataInfo(DataType::INT, "ID", true));
}

Table::Table(std::string table_name): Table(){
    this->table_name = std::move(table_name);
}

std::ostream &operator<<(std::ostream &os, const Table &t) {
}

void Table::insertColumnToExistingRows(const ColumnDataInfo &info) {
}

void Table::printTable() const{
    printColumnsInfo();
    printRows();
}

bool Table::insertData(std::vector<DataValue> data) {
    if(checkIfValidDataToInsert(data)){
        int id = primary_key_generator.getNextKey();
        Row row{id, data};
        rows.push_back(row);
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

template<typename T>
T min(const T& a, const T& b) {
    if (a < b) {
        return a;
    }
    return b;
}

template<typename T>
T min(T&& a, T&& b) {

}

template<typename...Ts>
struct AddToDataValueFn {
    static bool addToDataValue(DataValue* data_value, int value);
};

template<>
template<typename T, typename...Ts>
struct AddToDataValueFn<T, Ts...> {
    static bool addToDataValue(DataValue* data_value, int value) {
        if (AddToDataValueFn<T>::addToDataValue(data_value, value)) {
            return true;
        }
        return AddToDataValueFn<Ts...>::addToDataValue(data_value, value);
    }
};

template<>
template<typename T>
struct AddToDataValueFn<T> {
    static bool addToDataValue(DataValue* data_value, int value) {
        T* t = dynamic_cast<T*>(data_value);
        if (t != nullptr) {
            t->set(t->get() + value);
            return true;
        }
        return false;
    }
};

using AddToDataValue = AddToDataValueFn<INT, DOUBLE>;

struct AddToDataValueVariantFn {
    int value;

    bool operator()(INT& i) {
        i.set(i.get() + value);
        return true;
    }

    bool operator()(DOUBLE& d) {
        d.set(d.get() + value);
        return true;
    }

    template<typename T>
    bool operator()(T& t) {
        return false;
    }
};

bool Table::addToColumn(const std::string& column_name, int value) {
    // Each row has the same schema within the same table.
    for (Row& row : rows) {
        for (DataValue& data_value : row.getData()) {
//            if (!AddToDataValue::addToDataValue(data_value, value)) {
//                return false;
//            }
            // Operation is not supported for the given column.
//            return false;
            std::visit(AddToDataValueVariantFn{value}, data_value);
        }
    }
    return true;
}

std::string Table::getTableName() const{
    return table_name;
}

Table::Table(PrimaryKeyGenerator table_name) {

}

void Table::printColumnsInfo() const {
    for(int i=0;i<columns_info.size();i++){
        std::cout << columns_info[i].getFieldName() << '\t';
    }
    std::cout << '\n';
}

void Table::printRows() const {
    for(int i=0;i<rows.size();i++){
        rows[i].print();
    }
}

void Table::insertColumn(const ColumnDataInfo &column) {
    columns_info.push_back(column);
}

std::vector<ColumnDataInfo> Table::getColumnsInfo() const {
    return columns_info;
}

const std::vector<Row>& Table::getRows() const {
    return rows;
}

void Table::updateTableName(const std::string &new_name) {
    table_name = new_name;
}
