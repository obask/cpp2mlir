#ifndef CPP2MLIR_VALUE_ID_H
#define CPP2MLIR_VALUE_ID_H

//#include "Operator.h"
#include <string>
#include <sstream>
#include "model.h"
#include "Operator.h"

namespace mlir {

//    std::string genValueId(Operator* op) {
//        std::ostringstream ss;
//        ss << reinterpret_cast<std::uintptr_t>(op);
//        std::string id = ss.str();
//        return id.substr(id.length() - 4);
//    }

    class ValueId {
    public:
        virtual ~ValueId() = default;
        [[nodiscard]] virtual std::string toString() const = 0;
        [[nodiscard]] virtual SimpleName* getReturnName() const = 0;
        [[nodiscard]] virtual SimpleType* getReturnType() const = 0;
    };

    class VarValue : public ValueId {
    public:
        VarValue(SimpleName* returnName, SimpleType* returnType)
                : returnName(returnName), returnType(returnType) {}

        [[nodiscard]] std::string toString() const override { return returnName->toString(); }
        [[nodiscard]] SimpleName* getReturnName() const override { return returnName; }
        [[nodiscard]] SimpleType* getReturnType() const override { return returnType; }

    private:
        SimpleName* returnName;
        SimpleType* returnType;
    };

    class ValValue : public ValueId {
    public:
        ValValue(SimpleName* returnName, SimpleType* returnType)
                : returnName(returnName), returnType(returnType) {}

        [[nodiscard]] std::string toString() const override { return returnName->toString(); }
        [[nodiscard]] SimpleName* getReturnName() const override { return returnName; }
        [[nodiscard]] SimpleType* getReturnType() const override { return returnType; }

    private:
        SimpleName* returnName;
        SimpleType* returnType;
    };

    class Operator;

    class SsaValue : public ValueId {
    public:
        explicit SsaValue(Operator* ref) : ref(ref) {}

        [[nodiscard]] std::string toString() const override;

        [[nodiscard]] SimpleName* getReturnName() const override;

        [[nodiscard]] SimpleType* getReturnType() const override;

    private:
        Operator* ref;
    };

}  // namespace mlir


#endif //CPP2MLIR_VALUE_ID_H
