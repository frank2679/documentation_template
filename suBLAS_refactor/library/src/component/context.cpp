// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#include "context.h"

// API functions
sublasStatus_t sublasCreate(sublasHandle_t *handle) {
    if (!handle) {
        return SUBLAS_STATUS_INVALID_POINTER;
    } else {
        *handle = new sublasContext;
    }
    return SUBLAS_STATUS_SUCCESS;
}

sublasStatus_t sublasDestroy(sublasHandle_t handle) {
    if (handle == nullptr) {
        return SUBLAS_STATUS_NOT_INITIALIZED;
    } else {
        delete handle;
    }
    return SUBLAS_STATUS_SUCCESS;
}
