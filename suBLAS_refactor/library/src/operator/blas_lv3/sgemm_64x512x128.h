#ifndef _GEMM_H_
#define _GEMM_H_

#include <functional>
#include <memory>

#include "base/base.h"

class GEMMFloat64X512X128 {
  public:
    GEMMFloat64X512X128(){};
    ~GEMMFloat64X512X128(){};

    // used to instantiate an op
    MAKE_INSTANCE(GEMMFloat64X512X128);

  public:
    std::function<sublasStatus_t(int a)> Compute();
};

#endif