#include "ValueId.h"

namespace mlir {
    std::string SsaValue::toString() const {
        if (ref->returnNames.empty()) {
            return "%genValueId(ref)";
        } else {
            return ref->returnNames[0]->toString();
        }
    }

    SimpleType *SsaValue::getReturnType() const {
        if (!ref->returnTypes.empty()) {
            return ref->returnTypes[0];
        }
        // Handle error or return default value
        return nullptr;
    }

    SimpleName *SsaValue::getReturnName() const {
        if (!ref->returnNames.empty()) {
            return ref->returnNames[0];
        }
        // Handle error or return default value
        return nullptr;
    }

}