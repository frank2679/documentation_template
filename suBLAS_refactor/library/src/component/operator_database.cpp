#include "operator_database.h"

#include <iostream>

// !!! need this define
OperatorDatabase *OperatorDatabase::op_database_ = nullptr;

std::string DatatypetoString<float>::data_type_name = "Float";
std::string DatatypetoString<double>::data_type_name = "Double";

OperatorDatabase *OperatorDatabase::GetOperatorDatabase() {
    if (nullptr == op_database_) {
        op_database_ = new OperatorDatabase();
    }
    return op_database_;
}

void OperatorDatabase::DestroyOperatorDatabase() {
    if (nullptr != op_database_) {
        delete op_database_;
        op_database_ = nullptr;
    }
}

template <typename T_DATA> std::string GetDataTypeName() {
    std::string data_type_name;
    if (std::is_same<T_DATA, float>::value) {
        data_type_name = std::string("Float");
    }
    return data_type_name;
}

// operator name is the ID of real kernel
std::string MakeOperatorName(const std::string &op_name,
                             const std::string &data_type_name,
                             const std::string &core_name) {
    return std::move(op_name + "#" + data_type_name + "#" + core_name);
}

std::shared_ptr<Core>
OperatorDatabase::RegisterOperator(const std::string &op_name,
                                   const std::string &data_type_name,
                                   const std::string &core_name) {

    std::string operator_name =
        MakeOperatorName(op_name, data_type_name, core_name);
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