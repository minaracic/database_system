#include<iostream>

#include "src/server/server.h"

int main() {
    std::cout<<"Hello world!"<<std::endl;

    Server server("localhost");
    server.start_server();
    return 0;
}
