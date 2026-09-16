#include "database/Database.h"
#include <iostream>

int main() {
    Schema studentSchema({
        Column("id", DataType::INT),
        Column("name", DataType::TEXT),
        Column("cgpa", DataType::FLOAT)
    });

    Table students("students", studentSchema);
    
    Row student({
        Value(101),
        Value(std::string("Avisha")),
        Value(8.8f)
    });
    students.insertRow(student);
    Database db;
    db.addTable(students);
    Table* foundTable= db.getTable("students");
    if (foundTable!= nullptr) {
        std::cout<<foundTable->getName()<<"\n";
    }
    return 0;
}