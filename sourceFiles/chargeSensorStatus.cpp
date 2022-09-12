#include <iostream>
#include "../includes/chargeSensorStatus.hpp"
#include "random"

using namespace std;

vector<int> getCurrentListInAmps(int minimumValue, int maximumValue, int numberOfReadings)
{

  std::random_device rd;                         // obtain a random number from hardware
  std::mt19937 gen(rd());                        // seed the generator
  std::uniform_int_distribution<> distr(minimumValue, maximumValue); // define the range

  vector<int> currentListInAmps;

  for (int readCount = 0; readCount < numberOfReadings; readCount++)
  {
    currentListInAmps.push_back(distr(gen));
  }
  return currentListInAmps;
}
