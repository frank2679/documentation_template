#include <string>
using namespace std;
class Beverage {
  private:
    string description = "Unkonw Beverage";

  public:
    string getDescrition() { return description; }
    virtual double cost();
};

class CondimentDecorateor : public Beverage {
  public:
    string getDescrition();
};

class Espresso : public Beverage {
  private:
    string description;

  public:
    Espresso() { description = "Espresso"; }
    double cost() { return 1.99; }
};