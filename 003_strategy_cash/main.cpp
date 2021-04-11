/**
 * @file main.cpp
 * @author yanghang (you@domain.com)
 * @brief strategy + simple factory
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

enum CASH_TYPE {
    CASH_NORMAL,
    CASH_REBATE
};

class CashSuper {
  public:
    virtual double acceptCash(double money)=0;
};

class CashNormal: public CashSuper {
  public:
    double acceptCash(double money) {
        return money;
    }
};

class CashRebate:public CashSuper {
  private:
    double moneyRebate = 1.0;
  public: 
    CashRebate(double rebate): moneyRebate(rebate) {}
    double acceptCash(double money) {
        return money * moneyRebate;
    }
};


class CashContext {
  protected:
    CashSuper *cs;
  public:
    /**
     * @brief simple factory mode to create cs. In this way, CashContext will be 
     *        wrapped.
     */
    CashContext(CASH_TYPE type){
        switch (type) {
          case CASH_NORMAL:
            cs = new CashNormal;
            break;
          case CASH_REBATE:
            cs = new CashRebate(0.8);
            break;
        }
    }
    ~CashContext(){ delete cs; };
    double getResult(double money){ 
        cs->acceptCash(money);
    };
};

// 程序的主函数
int main()
{
    CashContext *cash_context = new CashContext(CASH_REBATE);
    double real_price = cash_context->getResult(100);
    cout << "real price: " << real_price << endl;
    return 0;
}
