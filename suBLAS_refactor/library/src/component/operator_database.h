#include <map>
#include <memory>
#include <string>

#include "base/base.h"
#include "core.h"

std::string MakeOperatorName(const std::string &op_name,
                             const std::string &data_type_name,
                             const std::string &algo_name);

template <typename T_DATA> class DatatypetoString {};

template <> class DatatypetoString<float> {
  public:
    static std::string data_type_name;
};

template <> class DatatypetoString<double> {
  public:
    static std::string data_type_name;
};

class OperatorDatabase {
    typedef std::map<std::string, std::shared_ptr<Core>> CoreDictionary;
    // typedef std::map<std::string, CoreDictionary> DatatypeDictionary;
    // typedef std::map<std::string, DatatypeDictionary> OperatorDictionary;

  private:
    OperatorDatabase(){};
    ~OperatorDatabase(){};

    // Done: singleton
    static OperatorDatabase *op_database_;

  public:
    static OperatorDatabase *GetOperatorDatabase();

    static void DestroyOperatorDatabase();

    std::shared_ptr<Core> RegisterOperator(const std::string &op_name,
                                           const std::string &data_type_name,
                                           const std::string &core_name);

    template <typename T_DATA, typename... ARGS>
    sublasStatus_t operator()(const std::string &op_name, ARGS... args) {

        // TBD: select the impl according to params
        std::string core_name("64X512X128");
        // std::string core_name = GetCoreName(args...);
        std::string data_type_name = DatatypetoString<T_DATA>::data_type_name;

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