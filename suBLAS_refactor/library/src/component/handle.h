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
    template <typename T_DATA, typename... ARGS>
    sublasStatus_t Execute(const std::string &op_name, ARGS... args) {
        return OperatorDatabase::GetOperatorDatabase()->operator()<T_DATA>(
            op_name, args...);
    }

    // TBD: set stream
};

typedef sublasContext *sublasHandle_t;

#endif // _CONTEXT_H_
