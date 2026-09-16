#include "storage/Row.h"
#include <iostream>

int main() {
    Row student({
        Value(101),
        Value(std::string("Avisha")),
        Value(8.8f)
    });
    std::vector<Value> values= student.getValues();
    std::cout << std::get<int>(values[0].getData()) << "\n";
    std::cout << std::get<std::string>(values[1].getData()) << "\n";
    std::cout << std::get<float>(values[2].getData()) << "\n";
    return 0;
}