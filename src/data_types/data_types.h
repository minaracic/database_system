#pragma once
#include <string>
#include <variant>

// TODO: make specialized data types more concrete: varchar(30), long text..

// can be implemented via templates,
// but in that case we cannot represent new data types to the users

enum DataType{
    INTEGER,
    DOUBLE,
    FLOAT,
    VARCHAR30,
    BOOLEAN
};

struct DataTypeFn {
    // TODO: Implement.
    // DataType data_type = std::visit(DataTypeFn{}, variant_value);
};

//inline constructor?
class Integer {
    int val;
public:
    Integer(int v = 0);
    void set(int v) {
        val = v;
    }
    int get() const {
        return val;
    }

    void print() const;
};

class Varchar30 {
    std::string val;
public:
    Varchar30(std::string v = "");

    void print() const;

    DataType getDataType() const {
        return DataType::VARCHAR30;
    }
};

class Double {
    double val = 0.0;
public:
    Double(double v = 0.0);

    void set(double v) {
        val = v;
    }

    double get() const {
        return val;
    }

    void print() const;
};

using DataValue = std::variant<Integer, Double, Varchar30>;

