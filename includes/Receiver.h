#include <stdio.h>
#include<stdlib.h>
#include <math.h>

#define numberofreading 50

void readDataFromConsole(float* Current, float* Temperature);
float maxValue(float *sensordata);
float minValue(float *sensordata);
float getSimpleMovingAverage(float *sensordata);
void receiveAndProcessSensorData(float* Current, float* Temperature);