#include <iostream>
#include "mlir/Operator.h"

using namespace mlir;

std::ostream &operator<<(std::ostream &out, const Operator &c) {
    out << "Op => ";
    out << c.name;
    out << ", ";
    out << c.dialect;
    out << ";";
    return out;
}

int main() {
    auto x = Operator();
    x.name = "dsafas";

    std::cout << x << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
