/**
 * @file main.cpp
 * @author yanghang (you@domain.com)
 * @brief template project
 * @version 0.1
 * @date 2021-04-19
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "foo.h"

#include <iostream>
#include <string>

int main() {
    std::cerr << "hello world" << std::endl;

    {
        // V1
        auto databasev1_1 = SingletonV1::GetInstance();
        databasev1_1.database.insert({"key1", 1});
        databasev1_1.database.insert({"key2", 2});
        databasev1_1.Print();
        auto databasev1_2 = SingletonV1::GetInstance();
        databasev1_2.Print();
    }

    {
        // V2 use inheritance
        auto a = Foo::GetInstance();
        a.Print();
        Foo::GetInstance().Print();
    }
    {
        // V3_1 map as singleton, failed
        auto database_int = Database<int>::GetInstance();
        database_int.insert({"hello", 3});
        auto database_str = Database<std::string>::GetInstance();
        database_str.insert({"num2", "value"});
        database_str.insert({"num3", "value2"});
        database_str.insert({"num4", "value2"});
        database_str.insert({"num5", "value2"});
        std::cout << "database_int: " << &database_int
                  << ", size: " << database_int.size() << std::endl;
        std::cout << "database_str: " << &database_str
                  << ", size: " << database_str.size() << std::endl;

        auto database_str2 = Database<std::string>::GetInstance();
        std::cout << "database_str: " << &database_str2
                  << ", size: " << database_str2.size() << std::endl;

        // V3_2
        auto databaseV3_2 = SingletonV3::GetInstance();
        databaseV3_2->insert({"key1", 1});
        databaseV3_2->insert({"key2", 2});
        // std::cout << databaseV3_2.size() << std::endl;
        std::cout << "type of databaseV3_2: " << typeid(databaseV3_2).name()
                  << std::endl;
        databaseV3_2->Print();
        auto databaseV3_2_2 = SingletonV3::GetInstance();
        databaseV3_2->Print();
    }

    {
        // V4 use template of V3_2
        auto foo4 = Foo4<int>::GetInstance();
        foo4->insert({"key1", 1});
        foo4->insert({"key2", 2});
        foo4->Print();
        auto foo4_2 = Foo4<int>::GetInstance();
        foo4_2->Print();
        auto foo4_3 = Foo4<std::string>::GetInstance();
        foo4_3->insert({"key1", "v1"});
        foo4_3->insert({"key2", "v1"});
        foo4_3->insert({"key3", "v1"});
        foo4_3->Print();

        std::cout << typeid(foo4).name() << ", " << typeid(foo4_2).name()
                  << ", " << typeid(foo4_3).name() << std::endl;

        Foo4<std::string> foo4_str;
        foo4_str.Print();
    }

    return 0;
}
