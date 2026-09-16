#include "storage/Table.h"
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

    std::vector<Row> rows= students.getRows();
    std::vector<Value> values= rows[0].getValues();
    std::cout << std::get<int>(values[0].getData()) << "\n";
    std::cout << std::get<std::string>(values[1].getData()) << "\n";
    std::cout << std::get<float>(values[2].getData()) << "\n";
    return 0;
}