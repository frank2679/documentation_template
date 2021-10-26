#ifndef _CORE_H_
#define _CORE_H_

#include <functional>
#include <iostream>
#include <map>
#include <string>

struct Core {
    Core(){};
    Core(const std::string &op_name) : op_name_(op_name){};
    ~Core(){};
    template <typename T, typename... ARGS>
    Core *RegisterFunction(std::function<T(ARGS...)> func) {
        auto item = LauncherDict<T, ARGS...>().insert({op_name_, func});
        if (!item.second) {
            std::cout << op_name_ << ": Operator name exists." << std::endl;
        }
        return this;
    }

    // interface for all operators
    template <typename T, typename... ARGS> T operator()(ARGS... args) {
        auto item = LauncherDict<T, ARGS...>().find(this->op_name_);
        if (LauncherDict<T, ARGS...>().end() != item) {
            auto ret = item->second(args...);
            return ret;
        }
    }

    template <typename T, typename... ARGS>
    static std::map<std::string, std::function<T(ARGS...)>> &LauncherDict() {
        static std::map<std::string, std::function<T(ARGS...)>>
            launcher_dictionary;
        return launcher_dictionary;
    }

  private:
    std::string op_name_;
};

#endif