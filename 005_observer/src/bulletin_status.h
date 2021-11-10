#include "observer.h"
#include "weather_data.h"

#include <iostream>
#include <string>

#ifndef BULLETIN_STATUS_H_
#define BULLETIN_STATUS_H_

class BulletinStatus : public Observer {
    typedef std::string Name;

  private:
    Name name_;
    // TBD, pointer vs reference
    Observable *weather_data_;
    float temperature_;
    float humidity_;

  public:
    BulletinStatus(Observable *weather_data, Name name)
        : name_(name), weather_data_(weather_data) {
        weather_data_->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure) {
        temperature_ = temperature;
        humidity_ = humidity;
        std::cout << "=======>hello: " << name_ << '\n';
        std::cout << "temperature: " << temperature_ << '\n';
        std::cout << "humidity: " << humidity_ << std::endl;
    }

    void RemoveFromWeatherData() { weather_data_->removeObserver(this); }

    Name GetName() { return name_; }
};

#endif