#pragma once

class PrimaryKeyGenerator{
    int ID;
public:
    PrimaryKeyGenerator():ID(0){};

    int getNextKey();
};