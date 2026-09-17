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
    bool insertRow(Row row){
        std::vector<Column> columns= schema.getColumns();
        std::vector<Value> values= row.getValues();
        if (values.size()==columns.size()){
            for (int i=0;i<values.size();i++){
                if(columns[i].getType() != values[i].getType()){
                    return false;
                }
            }
            rows.push_back(row);
            return true;
        }
        else return false;
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