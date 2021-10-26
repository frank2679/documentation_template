#include <map>
#include <memory>
#include <string>

#include "base/base.h"
#include "core.h"

std::string MakeOperatorName(const std::string &op_name,
                             const std::string &data_type_name,
                             const std::string &algo_name);

class OperatorDatabase {
    typedef std::map<std::string, std::shared_ptr<Core>> CoreDictionary;
    // typedef std::map<std::string, CoreDictionary> DatatypeDictionary;
    // typedef std::map<std::string, DatatypeDictionary> OperatorDictionary;

  private:
    OperatorDatabase(){};
    ~OperatorDatabase(){};

    // why this op_database_? different with operator_database_
    static OperatorDatabase *op_database_;

  public:
    static OperatorDatabase *GetOperatorDatabase();

    static void DestroyOperatorDatabase();

    std::shared_ptr<Core> RegisterOperator(const std::string &op_name,
                                           const std::string &data_type_name,
                                           const std::string &core_name);

    template <typename T_OP, typename T_DATA, typename T_ALGO, typename... ARGS>
    sublasStatus_t operator()(const T_OP &op_name, const T_DATA &data_type_name,
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