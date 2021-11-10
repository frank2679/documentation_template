/**
 * @file main.cpp
 * @author yanghang (you@domain.com)
 * @brief template project
 * @version 0.1
 * @date 2021-11-10
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "bulletin_average.h"
#include "bulletin_status.h"
#include "weather_data.h"

#include <iostream>

int main() {
    std::string status_name("status");
    std::string average_name("average");
    WeatherData *weather_data = new WeatherData();
    BulletinStatus bulletin_status(weather_data, status_name);
    BulletinAverage bulletin_average(weather_data, average_name);

    std::cout << "string: " << status_name << std::endl;

    std::cout << "------------------------" << std::endl;
    weather_data->setMeasurements(0.5, 2.0, 3.5);
    std::cout << "------------------------" << std::endl;
    weather_data->setMeasurements(100.5, 105.0, 3.5);
    std::cout << "------------------------" << std::endl;
    bulletin_average.RemoveFromWeatherData();
    weather_data->setMeasurements(50.5, 55.0, 3.5);

    std::cerr << "hello world" << std::endl;
    return 0;
}
