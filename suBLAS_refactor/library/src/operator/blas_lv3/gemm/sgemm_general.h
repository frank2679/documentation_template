#ifndef _SGEMM_GENERAL_H_
#define _SGEMM_GENERAL_H_

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

class GEMMFloatGENERAL {
  public:
    GEMMFloatGENERAL(){};
    ~GEMMFloatGENERAL(){};

    // used to instantiate an op
    MAKE_INSTANCE(GEMMFloatGENERAL);

  public:
    std::function<sublasStatus_t(COMPUTE_PARAMETER)> Compute();
};

#endif // _SGEMM_GENERAL_H_