#include "observer.h"

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

class Observable {
  public:
    virtual void registerObserver(Observer *obs) = 0;
    virtual void removeObserver(Observer *obs) = 0;
    virtual void notifyObserver() = 0;
};

#endif