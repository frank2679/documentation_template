#include "sgemm_64x512x128.h"

#include "component/operator_database.h"

REGISTER_OP(GEMM, Float, 64X512X128, 0)
    ->RegisterFunction(GEMMFloat64X512X128::Instance()->Compute());

std::function<sublasStatus_t(int)> GEMMFloat64X512X128::Compute() {
    return [](int a) {
        std::cout << "hello GEMMFloat64X512X128, input value: " << a
                  << std::endl;
        return SUBLAS_STATUS_SUCCESS;
    };
}