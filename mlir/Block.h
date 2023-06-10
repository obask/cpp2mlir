#ifndef CPP2MLIR_BLOCK_H
#define CPP2MLIR_BLOCK_H

#include "model.h"
#include "Operator.h"
//#include "BlockId.h"
//#include "SimpleName.h"
//#include "SimpleType.h"
#include <vector>
#include <utility>

namespace mlir {

    class Operator;
    class BlockId;
    class SimpleName;
    class SimpleType;

    class Block {
    public:
        Block()
                : operators(), name(nullptr), params() {}

        explicit Block(std::vector<Operator*> operators, BlockId* name = nullptr, std::vector<std::pair<SimpleName*, SimpleType*>> params = {})
                : operators(std::move(operators)), name(name), params(std::move(params)) {}

        void operator+=(Operator* that) {
            operators.push_back(that);
        }

        // Remember to implement copy constructor, assignment operator, and destructor if needed

    private:
        std::vector<Operator*> operators;
        BlockId* name;
        std::vector<std::pair<SimpleName*, SimpleType*>> params;
    };

}  // namespace mlir

#endif //CPP2MLIR_BLOCK_H
