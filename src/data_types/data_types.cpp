#include <iostream>

#include "data_types.h"

Integer::Integer(int v) {
//    value_type = DataType::INTEGER;
    val = v;
}

void Integer::print() const {
    std::cout << val << '\t';
}

void Varchar30::print() const {
    std::cout << val << '\t';
}

Varchar30::Varchar30(std::string v) {
//    value_type = DataType::VARCHAR30;
    val=v;
}

void Double::print() const {
    std::cout << val << '\t';
}

Double::Double(double v) {
//    value_type = DataType::DOUBLE;
    val=v;
}
