#pragma once

#include "Column.h"
#include <vector>

class Schema {
private:
    std::vector<Column> columns;
public:
    Schema(std::vector<Column> columns){
        this->columns= columns;
    }
    std::vector<Column> getColumns() {
        return columns;
    }
};