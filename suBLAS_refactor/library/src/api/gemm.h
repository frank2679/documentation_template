// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#ifndef _GEMM_H_
#define _GEMM_H_

#include "base/base.h"
#include "component/handle.h"

/// API template
template <typename T_DATA>
sublasStatus_t gemmApiTemplate(sublasHandle_t handle, sublasOperation_t transA,
                               sublasOperation_t transB, int m, int n, int k,
                               const T_DATA *alpha, const T_DATA *A, int lda,
                               const T_DATA *B, int ldb, const T_DATA *beta,
                               T_DATA *C, int ldc, const char api_function_[],
                               const char api_name_[]) {
    // TBD:
    // how to set data type according to T
    // how to generate the core name according to the params
    // return handle->Execute<T_DATA>(std::string("GEMM"), m);
    return handle->Execute<T_DATA>(std::string("GEMM"), transA, transB, m, n, k,
                                   alpha, A, lda, B, ldb, beta, C, ldc);
}
#endif