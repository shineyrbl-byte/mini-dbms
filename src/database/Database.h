#pragma once
#include "../storage/Table.h"
#include <vector>

class Database{
private:
    std::vector<Table> tables;
public:
    void addTable(Table table){
        tables.push_back(table);
    }
    Table* getTable(std::string name){
        for (Table& table: tables){
            if(table.getName()==name) return &table;
        }
        return nullptr;
    }
};