#ifndef SERVER_H
#define SERVER_H

#include<string>
#include<unordered_map>

#include"../database/database.h"

class Server {
    std::string address_;
    std::unordered_map<std::string, Database> databases_;
public:
    Server(const std::string &address) {address_ = address;}

    void start_server();
    void stop_server();

    void insert_database(Database& database);
    Database& get_database(const std::string& name);
};

#endif //SERVER_H
