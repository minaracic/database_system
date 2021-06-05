#include <iostream>

#include "data_types.h"

void DataValue::print() {
    std::cout << "Non" << "\t";
}

Integer::Integer(int v) {
    value_type = DataType::INTEGER;
    val = v;
}

void Integer::print() {
    std::cout << val << '\t';
}

void Varchar30::print() {
    std::cout << val << '\t';
}

Varchar30::Varchar30(std::string v) {
    value_type = DataType::VARCHAR30;
    val=v;
}

void Double::print() {
    std::cout << val << '\t';
}

Double::Double(double v) {
    value_type = DataType::DOUBLE;
    val=v;
}

void DataValue::setDataType(DataType type) {
    value_type = type;
}

DataType DataValue::getDataType() const {
    return value_type;
}
