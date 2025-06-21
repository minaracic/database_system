#pragma once
#include<exception>

class NotUniqueTableName: public std::exception{
public:
    constexpr static const auto msg = "Table with this name already exists.";
    const char * what() const noexcept override{
        return msg;
    }
};

class INT_TYPEOverflow: public std::exception{
public:
    constexpr static const auto msg = "INT_TYPE overflow. Value is not in the range.";
    const char * what() const noexcept override{
        return msg;
    }
};