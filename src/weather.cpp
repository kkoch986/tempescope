#include <weather.h>

Weather::Weather() {}

Weather::Weather(WeatherType weatherType){
  this->weatherType = weatherType;
}

WeatherType Weather::getWeatherType(){
  return this->weatherType;
}

void Weather::setWeatherType(WeatherType weatherType){
  this->weatherType = weatherType;
}