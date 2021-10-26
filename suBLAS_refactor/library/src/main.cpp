/**
 * @file main.cpp
 * @author yanghang (you@domain.com)
 * @brief template project
 * @version 0.1
 * @date 2021-04-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>

#include "inc/sublas.h"

int main() {

    sublasHandle_t handle;
    sublasCreate(&handle);

    int m = 64, n = 512, k = 128;
    int lda = m, ldb = k, ldc = m;
    float alpha = 1.0, beta = 0.0;
    float *ptr_a = nullptr;
    float *ptr_b = nullptr;
    float *ptr_c = nullptr;

    sublasSgemm(handle, SUBLAS_OP_N, SUBLAS_OP_N, m, n, k, &alpha, ptr_a, lda,
                ptr_b, ldb, &beta, ptr_c, ldc);

    std::cerr << "hello world" << std::endl;
    return 0;
}
