// These classes represent the data types that exist in the database.
// There are INT, DOUBLE, FLOAT, BOOLEAN and VARCHARN.
// INT - scalar singed values, from [-2^31-1, 2^31]
//
#pragma once
#include <string>
#include <variant>

// TODO: make specialized data types more concrete: varchar(30), long text..

// can be implemented via templates,
// but in that case we cannot represent new data types to the users

enum DataType{
    INT_TYPE,
    DOUBLE_TYPE
};

struct DataTypeFn {
    // TODO: Implement.
    // DataType data_type = std::visit(DataTypeFn{}, variant_value);
};

//inline constructor?
class INT_TYPE {
    int val;
public:
    explicit INT_TYPE(int v = 0):val(v) {};

    void set_val(const int v) {
        val = v;
    }

    int get_val() const {
        return val;
    }

    void print() const {std::cout << val << '\t';};
};

class DOUBLE_TYPE {
    double val = 0.0;
public:
    DOUBLE_TYPE(double v = 0.0): val(v) {};

    void set_val(double v) {
        val = v;
    }

    double get_val() const {
        return val;
    }

    void print() const { std::cout << val << '\t';};
};

using DataValue = std::variant<INT_TYPE, DOUBLE_TYPE>;

