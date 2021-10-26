// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "database/database.h"

class sublasContext {
  public:
    sublasContext() {}
    ~sublasContext() {}

    sublasContext(const sublasContext &) = delete;
    sublasContext(sublasContext &&) = delete;

  public:
    template <typename T_LAYER, typename T_MODE, typename T_ALGO,
              typename... ARGS>
    sublasStatus_t Execute(const T_LAYER &layer, const T_MODE &mode,
                           const T_ALGO &algo, ARGS... args) {
        return DataBase::GetOperatorDatabase()->operator()(layer, mode, algo,
                                                           args...);
    }
};

typedef sublasContext *sublasHandle_t;

#endif // _CONTEXT_H_
