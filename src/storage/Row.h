#pragma once
#include "../types/Value.h"
#include <vector>

class Row{
private:
    std::vector<Value> values;

public:
    Row(std::vector<Value> values){
        this->values= values;
    }
    std::vector<Value> getValues(){
        return values;
    }
};