#pragma once
#include <string>
#include <vector>

class Database{
    std::string database_name_;

public:
    Database(const std::string& name);

    void set_name(const std::string& name){database_name_=name;};
    std::string& get_name(){return database_name_;}
};