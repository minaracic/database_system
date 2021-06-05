#pragma once
#include <string>

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

class DataValue{
protected:
    DataType value_type;
public:
    void setDataType(DataType type);
    DataType getDataType() const;
    virtual void print();
};

//inline constructor?
class Integer: public DataValue{
    int val;
public:
    Integer(int v = 0);

    void print() override;
};

class Varchar30: public DataValue{
    std::string val;
public:
    Varchar30(std::string v = "");

    void print() override;
};

class Double: public DataValue{
    double val = 0.0;
public:
    Double(double v = 0.0);

    void print() override;
};

