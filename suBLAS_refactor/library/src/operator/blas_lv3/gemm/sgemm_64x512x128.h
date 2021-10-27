#ifndef _SGEMM_64X512X128_H_
#define _SGEMM_64X512X128_H_

#include <functional>
#include <memory>

#include "base/base.h"

#define COMPUTE_PARAMETER                                                      \
    PARAMETER_LIST(sublasOperation_t transA, sublasOperation_t transB, int m,  \
                   int n, int k, const float *alpha, const float *A, int lda,  \
                   const float *B, int ldb, const float *beta, float *C,       \
                   int ldc)
#define COMPUTE_ARGUMENT                                                       \
    PARAMETER_LIST(transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc)

class GEMMFloat64X512X128 {
  public:
    GEMMFloat64X512X128(){};
    ~GEMMFloat64X512X128(){};

    // used to instantiate an op
    MAKE_INSTANCE(GEMMFloat64X512X128);

  public:
    std::function<sublasStatus_t(COMPUTE_PARAMETER)> Compute();
};

#endif // _SGEMM_64X512X128_H_