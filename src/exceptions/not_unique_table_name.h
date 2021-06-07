#pragma once
#include<exception>

class NotUniqueTableName: public std::exception{
public:
    const char * what() const noexcept override{
        return "Table with this name already exists!";
    }
};