// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "component/operator_database.h"

class sublasContext {
  public:
    sublasContext() {}
    ~sublasContext() {}

    sublasContext(const sublasContext &) = delete;
    sublasContext(sublasContext &&) = delete;

  public:
    template <typename T_OP, typename T_DATA, typename T_ALGO, typename... ARGS>
    sublasStatus_t Execute(const T_OP &op, const T_DATA &data_type,
                           const T_ALGO &algo, ARGS... args) {
        return OperatorDatabase::GetOperatorDatabase()->operator()(
            op, data_type, algo, args...);
    }

    // TBD: set stream
};

typedef sublasContext *sublasHandle_t;

#endif // _CONTEXT_H_
