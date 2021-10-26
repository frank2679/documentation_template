// Copyright 2020, Biren Technologies Inc.
// All rights reserved.

#ifndef _SUBLAS_H_
#define _SUBLAS_H_

#if defined(__cplusplus)
extern "C" {
#endif
/// sublas error type
typedef enum {
    SUBLAS_STATUS_SUCCESS = 0,
    SUBLAS_STATUS_NOT_INITIALIZED = 1,
    SUBLAS_STATUS_INVALID_POINTER = 2,
    SUBLAS_STATUS_ALLOC_FAILED = 3,
    SUBLAS_STATUS_INVALID_VALUE = 7,
    SUBLAS_STATUS_ARCH_MISMATCH = 8,
    SUBLAS_STATUS_MAPPING_ERROR = 11,
    SUBLAS_STATUS_EXECUTION_FAILED = 13,
    SUBLAS_STATUS_INTERNAL_ERROR = 14,
    SUBLAS_STATUS_NOT_SUPPORTED = 15,
    SUBLAS_STATUS_LICENSE_ERROR = 16,
    SUBLAS_STATUS_MEMORY_DEMAND_INCREASED = 17,
    SUBLAS_STATUS_MEMORY_DEMAND_UNCHANGED = 18,
    SUBLAS_STATUS_MEMORY_DEMAND_MISMATCH = 19,
    SUBLAS_STATUS_MEMCPY_FAILED = 20
} sublasStatus_t;

typedef enum {
    SUBLAS_OP_N = 0,
    SUBLAS_OP_T = 1,
    SUBLAS_OP_C = 2,
    SUBLAS_OP_HERMITAN = 2, /* synonym if SUBLAS_OP_C */
    SUBLAS_OP_CONJG = 3     /* conjugate */
} sublasOperation_t;

// Defining sublas types
typedef float sublasFloat_t;
typedef double sublasDouble_t;
typedef struct sublasContext *sublasHandle_t;

/**
 * @brief
 *
 * @param _handle
 * @return sublasStatus_t
 */
sublasStatus_t sublasCreate(sublasHandle_t *_handle);

/**
 * @brief
 *
 * @param _handle
 * @return sublasStatus_t
 */
sublasStatus_t sublasDestroy(sublasHandle_t _handle);

/**
 * @brief compute
 *          C = alpha * op(A) * op(B) + beta * C
 *        where op( X ) = X      or
 *              op( X ) = X**T   or
 *              op( X ) = X**H,
 *
 * @param handle
 * @param transA
 * @param transB
 * @param m
 * @param n
 * @param k
 * @param alpha
 * @param A
 * @param lda
 * @param B
 * @param ldb
 * @param beta
 * @param C
 * @param ldc
 * @return sublasStatus_t
 */
sublasStatus_t sublasSgemm(sublasHandle_t handle, sublasOperation_t transA,
                           sublasOperation_t transB, int m, int n, int k,
                           const float *alpha, const float *A, int lda,
                           const float *B, int ldb, const float *beta, float *C,
                           int ldc);

#if defined(__cplusplus)
}
#endif

#endif // _SUBLAS_H_