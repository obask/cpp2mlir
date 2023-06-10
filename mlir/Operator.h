#ifndef CPP2MLIR_OPERATOR_H
#define CPP2MLIR_OPERATOR_H


//#include "DefaultMlirPrinter.h"
//#include "GhostPrettyPrinter.h"
#include "ValueId.h"
#include "Block.h"
//#include "Attribute.h"
#include "Attribute.h"
//#include "SimpleName.h"
//#include "StringAttr.h"
#include <vector>
#include <map>
#include <string>


namespace mlir {

    class Operator;
    class ValueId;

    class DefaultMlirPrinter {
    public:
        void renderOperatorRhsImpl(const mlir::Operator& anOperator, const std::string& string) {

        }
    };

    class GhostPrettyPrinter {
    public:
        void renderOperatorRhsImpl(const mlir::Operator& anOperator, const std::string& string) {

        }

    };

    class Operator {

    public:
        std::string name;
        std::string dialect = "scheme";
        std::vector<ValueId*> arguments;
        std::vector<Block*> blocks;
        std::map<std::string, Attribute*> attributes;
        std::vector<SimpleType*> argumentTypes;

//        virtual std::string getName() = 0;
//        virtual std::string getDialect() = 0;
//        virtual Operator* createInstance() = 0;
//
//        virtual void renderDefaultRhs(DefaultMlirPrinter& printer, const std::string& indent) {
//            printer.renderOperatorRhsImpl(*this, indent);
//        }
//
//        virtual void renderGhostRhs(GhostPrettyPrinter& printer, const std::string& indent) {
//            printer.renderOperatorRhsImpl(*this, indent);
//        }

//        Operator* clone() {
//            Operator* copy = this->createInstance();
//            copy->returnNames = returnNames;
//            copy->arguments = arguments;
//            copy->blocks = blocks;
//            copy->attributes = attributes;
//            copy->argumentTypes = argumentTypes;
//            copy->returnTypes = returnTypes;
//            return copy;
//        }

        void setAttribute(const std::string& field, const std::string& value) {
            attributes[field] = new StringAttr(value);
        }

        void setAttribute(const std::string& field, Attribute* value) {
            attributes[field] = value;
        }

        virtual ~Operator() = default;

        std::vector<SimpleName*> returnNames;
        std::vector<SimpleType*> returnTypes;
        Operator() = default;
    };

}  // namespace mlir


#endif //CPP2MLIR_OPERATOR_H
