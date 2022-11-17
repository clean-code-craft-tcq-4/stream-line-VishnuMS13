#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include <iostream>
#include "includes/chargeSensorStatus.hpp"
#include "includes/temperatureSensorStatus.hpp"
#include <vector>
#include "includes/sensorDataSender.hpp"

using namespace std;

TEST_CASE("TestTemperatureSensorValues") {
  vector<int> generatedTemperatureValues = getTemperatureInCelcious(TEMPERATURE_MIN_VALUE, TEMPERATURE_MAX_VALUE, WRITE_COUNT);

  REQUIRE(generatedTemperatureValues.size() == WRITE_COUNT);
}

TEST_CASE("TestCurrentSensorValues") {
  vector<int> currentListInAmps = getCurrentListInAmps(MIN_AMP, MAX_AMP, WRITE_COUNT);
  
  REQUIRE(currentListInAmps.size() == WRITE_COUNT);
}

TEST_CASE("TestWriteStatus") {
  
  REQUIRE(writeDataToConsole() == true);
}


