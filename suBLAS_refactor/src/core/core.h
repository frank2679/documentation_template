#ifndef _CORE_H_
#define _CORE_H_

#include <functional>
#include <iostream>
#include <map>
#include <string>

struct Core {
    typedef std::map<std::string, std::function<int(int)>> LauncherDictionary;
    Core(){};
    Core(const std::string &op_name) : op_name_(op_name){};
    ~Core(){};
    Core *RegisterFunction(std::function<int(int)> func) {
        auto item = LauncherDict().insert({op_name_, func});
        if (!item.second) {
            std::cout << op_name_ << ": Operator name exists." << std::endl;
        }
        return this;
    }

    // interface for all operators
    int operate(int a) {
        auto item =
            LauncherDict().find(this->op_name_); // TBD, convfwd is a core?
        if (LauncherDict().end() != item) {
            auto ret = item->second(a);
            return ret;
        }
    }

    static LauncherDictionary &LauncherDict() {
        static LauncherDictionary launcher_dictionary;
        return launcher_dictionary;
    }

  private:
    std::string op_name_;
};

#endif