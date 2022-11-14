#include "../includes/Receiver.h"
#include "../includes/sensorDataSender.hpp"

void readDataFromConsole(float* Current, float* Temperature){
    for (int i = 0; i < numberofreading; i++ )
     {
        scanf("%f,%f\n", &Current[i], &Temperature[i]);
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
   for(int i=(numberofreading-4) ; i <= numberofreading; i++)
   {
     sum += sensordata[i];
   }
   average = sum/5.00 ;// Divide by 5 to get the average of last 5 values
   return average;
}

int printReceivedDataToConsole(float *sensorparameter){
  printf("Data received from sender\n");
  for(int index = 0; index < numberofreading; index++)
  {
    printf("%f\n",sensorparameter[index]);
  }
  return 1;
}

void receiveAndProcessSensorData(float* Current, float* Temperature){
   readDataFromConsole(Current,Temperature);
   }
