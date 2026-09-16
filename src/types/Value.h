#pragma once
#include "DataType.h"
#include <variant>
#include <string>

class Value{
private:
    DataType type;
    std::variant<int,float,std::string> data;
public:
    Value(int x){
        type= DataType::INT;
        data=x;
    }
    Value(float x){
        type= DataType::FLOAT;
        data=x;
    }
    Value(std::string x){
        type=DataType::TEXT;
        data=x;
    }
    DataType getType() {
        return type;
    }
    const std::variant<int,float,std::string>& getData() const {
        return data;
    }
};
