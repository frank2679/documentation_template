#include <map>
#include <memory>
#include <string>

#include "base/base.h"
#include "core/core.h"

std::string MakeOperatorName(const std::string &op_name,
                             const std::string &data_type_name,
                             const std::string &algo_name);

class DataBase {
    typedef std::map<std::string, std::shared_ptr<Core>> CoreDictionary;
    // typedef std::map<std::string, CoreDictionary> DatatypeDictionary;
    // typedef std::map<std::string, DatatypeDictionary> OperatorDictionary;

  private:
    DataBase(){};
    ~DataBase(){};

    // why this op_database_? different with operator_database_
    static DataBase *op_database_;

  public:
    static DataBase *GetOperatorDatabase();

    static void DestroyOperatorDatabase();

    std::shared_ptr<Core> registerOperator(const std::string &op_name,
                                           const std::string &data_type_name,
                                           const std::string &core_name);

    template <typename T_LAYER, typename T_MODE, typename T_ALGO,
              typename... ARGS>
    sublasStatus_t operator()(const T_LAYER &op_name,
                              const T_MODE &data_type_name,
                              const T_ALGO &core_name, ARGS... args) {

        std::shared_ptr<Core> result;
        std::string operator_name =
            MakeOperatorName(op_name, data_type_name, core_name);
        auto iter = operator_database_.find(operator_name);
        if (operator_database_.end() != iter) {
            result = iter->second;
        } else {
            std::cout << "No such operator: " << operator_name << std::endl;
            return SUBLAS_STATUS_NOT_SUPPORTED;
        }

        return result->operator()<sublasStatus_t, ARGS...>(args...);
    }

  private:
    // OperatorDictionary operator_dictionary_;
    CoreDictionary operator_database_;
};