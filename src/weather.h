#ifndef weather_h
#define weather_h
#include <Arduino.h>

enum WeatherType{
  Clear,
  Rain,
  Cloudy,
  Storm,
  Hurricane,
  Tornado
};
  
class Weather {
  public:
  Weather();
  Weather(WeatherType weatherType);
  WeatherType setWeatherType(WeatherType weatherType);
  WeatherType getWeatherType();
  
  private:  
  WeatherType weatherType;
};

#endif