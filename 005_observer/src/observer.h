#include <string>

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
  public:
    virtual void update(float v1, float v2, float v3) = 0;
    virtual std::string GetName() = 0;
    virtual void RemoveFromWeatherData() = 0;
};

#endif