#include <map>
#include <memory>
#include <string>

#include "core/core.h"

class DataBase {
    typedef std::map<std::string, std::shared_ptr<Core>> CoreDictionary;

    // why these two dictionary?
    // typedef std::map<std::string, CoreDictionary> ModeDictionary;
    // typedef std::map<std::string, ModeDictionary> LayerDictionary;

  private:
    DataBase(){};
    ~DataBase(){};

    // why this op_database_? different with operator_database_
    static DataBase *op_database_;

  public:
    static DataBase *GetOperatorDatabase();

    static void DestroyOperatorDatabase();

    std::shared_ptr<Core> registerOperator(const std::string &layer_name,
                                           const std::string &mode_name,
                                           const std::string &core_name);

    int operate(const std::string &layer_name, const std::string &mode_name,
                const std::string &core_name);

  private:
    // LayerDictionary operator_dictionary_;
    CoreDictionary operator_database_;
};