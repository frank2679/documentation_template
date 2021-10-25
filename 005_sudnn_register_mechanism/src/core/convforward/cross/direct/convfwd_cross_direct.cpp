#include <iostream>
#include <string>

#include "database/database.h"

#include "convfwd_cross_direct.h"

// TBD: why static?
// register the op
// will non-used op be registered?
static auto kOpRegisterConvfwdCrossDirect =
    DataBase::GetOperatorDatabase() -> registerOperator(
        std::string("Convfwd"), std::string("Cross"), std::string("Direct"))
        -> RegisterFunction(ConvfwdCrossDirect::Instance()->Compute());

// TBD: only lamdba could be used?
std::function<int(int a)> ConvfwdCrossDirect::Compute() {
    // std::cout << "hello ConvfwdCrossDirect, input value: " << a << std::endl;
    // return 0;
    return [](int a) {
        std::cout << "hello ConvfwdCrossDirect, input value: " << a
                  << std::endl;
        return 0;
    };
}
