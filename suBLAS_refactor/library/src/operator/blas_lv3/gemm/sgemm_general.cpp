#include "sgemm_general.h"

#include "component/operator_database.h"

REGISTER_OP(GEMM, Float, GENERAL, 0)
    ->RegisterFunction(GEMMFloatGENERAL::Instance()->Compute());

std::function<sublasStatus_t(COMPUTE_PARAMETER)> GEMMFloatGENERAL::Compute() {
    return [](COMPUTE_PARAMETER) {
        std::cout << "hello GEMMFloatGENERAL, input value: " << m << std::endl;
        return SUBLAS_STATUS_SUCCESS;
    };
}