#include <iostream>

#include "database.h"

// !!! need this define
DataBase *DataBase::op_database_ = nullptr;

DataBase *DataBase::GetOperatorDatabase() {
    if (nullptr == op_database_) {
        op_database_ = new DataBase();
    }
    return op_database_;
}

void DataBase::DestroyOperatorDatabase() {
    if (nullptr != op_database_) {
        delete op_database_;
        op_database_ = nullptr;
    }
}

// operator name is the ID of real kernel
std::string MakeOperatorName(const std::string &layer_name,
                             const std::string &mode_name,
                             const std::string &core_name) {
    return std::move(layer_name + "#" + mode_name + "#" + core_name);
}

std::shared_ptr<Core> DataBase::registerOperator(const std::string &layer_name,
                                                 const std::string &mode_name,
                                                 const std::string &core_name) {

    std::string operator_name =
        MakeOperatorName(layer_name, mode_name, core_name);
    auto iter = operator_database_.find(operator_name);
    if (operator_database_.end() == iter) {
        auto item = operator_database_.insert(
            {operator_name, std::make_shared<Core>(operator_name)});

        auto result = item.first;
        return result->second;
    } else {
        std::cout << "Duplicate registration of operation name: "
                  << operator_name << std::endl;
        return iter->second;
    }
}

int DataBase::operate(const std::string &layer_name,
                      const std::string &mode_name,
                      const std::string &core_name) {
    std::shared_ptr<Core> result;
    std::string operator_name =
        MakeOperatorName(layer_name, mode_name, core_name);
    auto iter = operator_database_.find(operator_name);
    if (operator_database_.end() != iter) {
        result = iter->second;
    } else {
        std::cout << "No such operator: " << operator_name << std::endl;
        return 1;
    }

    return result->operate(5);
}