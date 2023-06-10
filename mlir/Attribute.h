#ifndef CPP2MLIR_ATTRIBUTE_H
#define CPP2MLIR_ATTRIBUTE_H


#include <string>
#include <utility>

class Attribute {

};


class StringAttr : public Attribute {
    std::string value;

public:
    explicit StringAttr(std::string value) : value(std::move(value)) {}


};

#endif //CPP2MLIR_ATTRIBUTE_H
