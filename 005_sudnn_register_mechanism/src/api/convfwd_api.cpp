#include <string>

#include "database/database.h"

int ConvFwdCrossDirect(int a) {
    return DataBase::GetOperatorDatabase()->operate(
        std::string("Convfwd"), std::string("Cross"), std::string("Direct"));
}