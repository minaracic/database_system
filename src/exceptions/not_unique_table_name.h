#pragma once
#include<exception>

class NotUniqueTableName: public std::exception{
public:
    constexpr static const auto msg = "Table with this name already exists!";
    const char * what() const noexcept override{
        return "Table with this name already exists!";
    }
};