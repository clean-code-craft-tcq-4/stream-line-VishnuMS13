#include "../includes/Receiver.h"

void readDataFromConsole(float* Current, float* Temperature){
    for (int i = 0; i < numberofreading; i++ )
     {
        scanf("%f,%f", &Current[i], &Temperature[i]);
     }
}

float minValue(float *sensordata){
  float minvalue = sensordata[0];
  for (int i = 0; i< numberofreading;i++){
    if(sensordata[i]<minvalue)
    minvalue = sensordata[i];
  }
  return minvalue;
}

float maxValue(float *sensordata){
  float maxValue = sensordata[0];
  for (int i = 0; i< numberofreading;i++){
    if(sensordata[i]>maxValue)
    maxValue = sensordata[i];
  }
  return maxValue;
}

float getSimpleMovingAverage(float *sensordata){
    //To get SMA of last 5 values
   float average = 0.0;
   float sum = 0.0;
   for(int i=0 ; i < numberofreading-5; i++)
   {
     sum += sensordata[i];
   }
   average = sum/5 ;// Divide by 5 to get the average of last 5 values
   return average;
}

void receiveAndProcessSensorData(float* Current, float* Temperature){
   readDataFromConsole(Current,Temperature);
   }
