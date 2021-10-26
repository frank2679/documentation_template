// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#ifndef _MACROS_H_
#define _MACROS_H_

#define SUBLAS_API extern "C" __attribute__((visibility("default")))
#define SUBLAS_LOCAL extern "C" __attribute__((visibility("hidden")))

#define REGISTER_OP(OpName, DataTypeName, CoreName, CoreId)                    \
    static auto kOpRegister##OpName##DataTypeName##CoreName =                  \
        OperatorDatabase::GetOperatorDatabase()->RegisterOperator(             \
            std::string(#OpName), std::string(#DataTypeName),                  \
            std::string(#CoreName))

#define MAKE_INSTANCE(OpName)                                                  \
    static std::shared_ptr<OpName> Instance() {                                \
        static std::shared_ptr<OpName> ptr;                                    \
        if (!ptr.get()) {                                                      \
            ptr = std::make_shared<OpName>();                                  \
        }                                                                      \
        return ptr;                                                            \
    }

#endif // _MACROS_H_