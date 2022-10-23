
#include <iostream>
#include "../includes/chargeSensorStatus.hpp"
#include "../includes/temperatureSensorStatus.hpp"
#include <vector>
#include "../includes/sensorDataSender.hpp"

using namespace std;

bool writeDataToConsole()
{
  bool writeStatus = false;
  vector<int> currentListInAmps = getCurrentListInAmps(MIN_AMP, MAX_AMP, WRITE_COUNT);
  vector<int> temperatureListInCelcious = getTemperatureInCelcious(TEMPERATURE_MIN_VALUE, TEMPERATURE_MAX_VALUE, WRITE_COUNT);

  if ((currentListInAmps.size() == WRITE_COUNT) && (temperatureListInCelcious.size() == WRITE_COUNT))
  {
    for (int counter = 0; counter < WRITE_COUNT; counter++)
    {
      cout << "Current : " << currentListInAmps[counter] << ", " << "Temprature : " << temperatureListInCelcious[counter] << endl;
    }

    writeStatus = true;
  }

  return writeStatus;
}
