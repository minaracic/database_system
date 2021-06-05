#pragma once
#include<string>
#include<iostream>

#include "../data_types/data_types.h"

class ColumnDataInfo{
    DataType data_type;
    std::string field_name;
    bool is_primary_key;
    DataValue* default_value;
public:
    ColumnDataInfo(DataType t, std::string f, bool is_pk);

    void setDefaultValue(DataValue* value);

    std::string getFieldName() const;
    DataType getDataType() const;

    static void print(const ColumnDataInfo& column);
};