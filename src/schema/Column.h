#pragma once

#include "../types/DataType.h"
#include <string>

class Column {
private:
    std::string name;
    DataType type;
public:
    Column(std::string name, DataType type){
        this->name= name;
        this->type= type;
    }
    std::string getName() {
        return name;
    }
    DataType getType(){
        return type;
    }
};