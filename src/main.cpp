#include "schema/Schema.h"
#include <iostream>

int main() {
    Schema studentSchema({
        Column("id", DataType::INT),
        Column("name", DataType::TEXT),
        Column("cgpa", DataType::FLOAT)
    });
    std::vector<Column> columns= studentSchema.getColumns();
    for (Column column: columns){
        std::cout<<column.getName() << "\n";
    }
    return 0;
}