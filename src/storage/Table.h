#pragma once
#include "../schema/Schema.h"
#include "Row.h"
#include <string>
#include <vector>

class Table{
private:
    std::string name;
    Schema schema;
    std::vector<Row> rows;

public:
    Table(std::string name, Schema schema)
        : name(name), schema(schema){
    }
    void insertRow(Row row){
        rows.push_back(row);
    }
    std::string getName(){
        return name;
    }
    Schema getSchema(){
        return schema;
    }
    std::vector<Row> getRows(){
        return rows;
    }
};