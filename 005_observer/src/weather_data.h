#include "observable.h"

#include <iostream>
#include <map>
#include <memory>
#include <string>

#ifndef WEATHERDATA_H_
#define WEATHERDATA_H_

class WeatherData : public Observable {
    typedef std::string Name;

  private:
    std::map<Name, Observer *> observers;
    float temperature_;
    float humidity_;
    float pressure_;

  public:
    WeatherData() {}
    // TBD could shared_ptr as argument
    void registerObserver(Observer *obs) {
        // TBD
        // observers.insert(std::pair<Name, Observer>(obs.GetName(), obs));
        observers[obs->GetName()] = obs;
    }

    void removeObserver(Observer *obs) {
        Name remove_name = obs->GetName();
        auto it = observers.find(remove_name);
        if (it != observers.end()) {
            observers.erase(it);
        } else {
            std::cerr << "No such observer is registered: " << remove_name
                      << std::endl;
        }
    }

    void notifyObserver() {
        auto it = observers.begin();
        for (; it != observers.end(); it++) {
            it->second->update(temperature_, humidity_, pressure_);
        }
    }

    void MeasurementChanged() { notifyObserver(); }

    void setMeasurements(float temperature, float humidity, float pressure) {
        temperature_ = temperature;
        humidity_ = humidity;
        pressure_ = pressure;
        MeasurementChanged();
    }
};

#endif