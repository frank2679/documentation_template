/**
 * @file main.cpp
 * @author yanghang (you@domain.com)
 * @brief QuackBehavior as an interface class, it can be used to declare a pointer variable. 
 *        This is a strategy design pattern.
 * @version 0.1
 * @date 2021-04-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <list>

using namespace std;

class QuackBehavior {
  public:
    virtual void quack()=0;
};

class Quack: public QuackBehavior {
  public:
    void quack() {
        cout << "qua qua" << endl;
    }
};

class Squark:public QuackBehavior {
  public: 
    void quack() {
        cout << "zhi zhi" << endl;
    }
};


class Duck {
  protected:
    QuackBehavior *quackbehavior;
  public:
    Duck(QuackBehavior *qb):quackbehavior(qb){}
    ~Duck(){};
    void performQuack(){ 
        quackbehavior->quack();
    };
};

class MallardDuck: public Duck{
    public:
    MallardDuck(QuackBehavior *qb):Duck(qb){}
    ~MallardDuck() {}
};

// 程序的主函数
int main()
{
    Squark quack;
    MallardDuck mallardduck(&quack);
    mallardduck.performQuack();
    return 0;
}
