#include "column_data_info.h"

ColumnDataInfo::ColumnDataInfo(DataType t, std::string f, bool is_pk) {
    data_type = t;
    is_primary_key = is_pk;
    field_name = f;
}

DataType ColumnDataInfo::getDataType() const {
    return data_type;
}

std::string ColumnDataInfo::getFieldName() const {
    return field_name;
}

void ColumnDataInfo::print(const ColumnDataInfo &column) {
    std::cout << column.field_name << '\t' << column.data_type << '\t'
              << column.is_primary_key << '\t';
}

void ColumnDataInfo::setDefaultValue(DataValue *value) {
    default_value = value;
}
