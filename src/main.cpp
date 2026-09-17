#include "database/Database.h"
#include <iostream>

int main() {
    Schema studentSchema({
        Column("id", DataType::INT),
        Column("name", DataType::TEXT),
        Column("cgpa", DataType::FLOAT)
    });

    Table students("students", studentSchema);
    
    Row validStudent({
        Value(101),
        Value(std::string("Avisha")),
        Value(8.8f)
    });
    Row wrongCount({
        Value(102),
        Value(std::string("Rahul"))
    });
    Row wrongType({
        Value(std::string("Avisha")),
        Value(103),
        Value(8.5f)
    });
    
    std::cout<<students.insertRow(validStudent)<<"\n";
    std::cout<<students.insertRow(wrongCount)<<"\n";
    std::cout<<students.insertRow(wrongType)<<"\n";
    return 0;
}