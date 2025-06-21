#include "server.h"

#include <iostream>
#include <ostream>

void Server::start_server() {
    std::cout << "Server started." << std::endl;
    while (true) {
    }
}

void Server::stop_server() {
}

void Server::insert_database(Database& database) {
    databases_.try_emplace(database.get_name(), database);
}

Database& Server::get_database(const std::string& name) {
    //return databases_[name];
}
