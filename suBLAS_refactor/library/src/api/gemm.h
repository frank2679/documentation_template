// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#ifndef _GEMM_H_
#define _GEMM_H_

#include "base/base.h"
#include "component/handle.h"

/// API template
template <typename T>
sublasStatus_t gemmApiTemplate(sublasHandle_t handle, sublasOperation_t transA,
                               sublasOperation_t transB, int m, int n, int k,
                               const float *alpha, const float *A, int lda,
                               const float *B, int ldb, const float *beta,
                               float *C, int ldc, const char api_function_[],
                               const char api_name_[]) {
    // TBD: how to set data type according to T
    return handle->Execute(std::string("GEMM"), std::string("Float"),
                           std::string("64X512X128"), m);
}
#endif