/**
 * @file main.cpp
 * @author yanghang (you@domain.com)
 * @brief factory
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <list>
#include <string>

using namespace std;

enum OPERATE_TYPE {
    ADD,
    SUB,
    MUL,
    DIV,
};

class Operation {
  public:
    double opA;
    double opB;
    virtual double getResult()=0;
};

class OperationAdd: public Operation {
  public:
    double getResult() {
        return opA + opB;
    }
};

class OperationSub:public Operation {
  public: 
    double getResult() {
        return opA - opB;
    }
};


class OperationMul:public Operation {
  public: 
    double getResult() {
        return opA * opB;
    }
};


class OperationDiv:public Operation {
  public: 
    double getResult() {
        return opA / opB;
    }
};


class OperationFactory {
  public:
    static Operation *createOperation(OPERATE_TYPE type) {
        Operation *oper = nullptr;
        switch (type) {
          case ADD:
            oper = new OperationAdd;
            break;
          case SUB:
            oper = new OperationSub;
            break;
          case MUL:
            oper = new OperationMul;
            break;
          case DIV:
            oper = new OperationDiv;
        }
        return oper;
    } 
};

// 程序的主函数
int main()
{
    Operation *oper;
    OperationFactory factory;
    OPERATE_TYPE type = SUB;
    oper = factory.createOperation(type);
    oper->opA = 2.0;
    oper->opB = 3.0;
    cout << "result : " << oper->getResult() << endl;
    return 0;
}
