#include <iostream>
#include "../includes/temperatureSensorStatus.hpp"
#include "random"

using namespace std;

vector<int> getTemperatureInCelcious(int minTemperatureValue, int maxTemperatureValue, int numberOfReadings)
{

  std::random_device rd;                         // obtain a random number from hardware
  std::mt19937 gen(rd());                        // seed the generator
  std::uniform_int_distribution<> distr(minTemperatureValue, maxTemperatureValue);

  vector<int> temperatureListInCelcious;
  
  for (int readCount = 0; readCount < numberOfReadings; readCount++)
  {
    temperatureListInCelcious.push_back(distr(gen));
  }
  return temperatureListInCelcious;
}



