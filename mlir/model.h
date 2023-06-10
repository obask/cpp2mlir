#ifndef CPP2MLIR_MODEL_H
#define CPP2MLIR_MODEL_H

#include "Operator.h"
#include <string>
#include <utility>
#include <vector>

namespace mlir {

//    class UastOperator : public Operator {
//    public:
//        explicit UastOperator(std::string  name) : Operator(), name(std::move(name)) {}
//
//        std::string getName() override { return name; }
//        std::string getDialect() override { return "uast"; }
//        Operator* createInstance() override { return new UastOperator(name); }
//
//    private:
//        std::string name;
//    };
//
//    class FirOperator : public Operator {
//    public:
//        explicit FirOperator(std::string  name) : Operator(), name(std::move(name)) {}
//
//        std::string getName() override { return name; }
//        std::string getDialect() override { return "fir"; }
//        Operator* createInstance() override { return new FirOperator(name); }
//
//    private:
//        std::string name;
//    };

    class BlockId {
    public:
        explicit BlockId(std::string  value) : value(std::move(value)) {}
        [[nodiscard]] std::string toString() const { return "^" + value; }

    private:
        std::string value;
    };

    class SimpleName {
    public:
        explicit SimpleName(std::string  name) : name(std::move(name)) {}
        [[nodiscard]] std::string toString() const { return "%" + name; }
        [[nodiscard]] std::string toGhost() const { return "v" + name; }

    private:
        std::string name;
    };

    class SimpleType {
    public:
        explicit SimpleType(std::string  type) : name(std::move(type)) {}
        [[nodiscard]] std::string toString() const { return "%" + name; }
        [[nodiscard]] std::string toGhost() const { return "v" + name; }

    private:
        std::string name;
    };

// Other class and interface definitions ...

}  // namespace mlir


#endif //CPP2MLIR_MODEL_H
