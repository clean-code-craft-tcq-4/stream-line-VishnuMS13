#include "includes/Receiver.h"
#include "includes/sensorDataSender.hpp"
#include <assert.h>

//Check if min and max values are within limits and display on the console
void Test_case1(){
    float Temperature[numberofreading] = {0};
    float Current[numberofreading]= {0};
    float obtainedminvalue, obtainedmaxvalue, expectedminvalue, expectedmaxvalue, SMATemp, SMACurrent;
    receiveAndProcessSensorData(&Current[0],&Temperature[0]);
    
    //Current
    expectedmaxvalue = 15;
    expectedminvalue = -15;
    obtainedminvalue = minValue(&Current[0]);
    obtainedmaxvalue = maxValue(&Current[0]);
    SMACurrent = getSimpleMovingAverage(&Current[0]);

    printf("Current values from sender");
    printReceivedDataToConsole(Current);
    printf("The Minimum value of Current is %.2f \n",obtainedminvalue);
    printf("The Maximum value of Current is %.2f \n",obtainedmaxvalue);
    printf("The SMA of Current is %.2f \n",SMACurrent);

    assert(obtainedminvalue >= expectedminvalue);
    assert(obtainedmaxvalue <= expectedmaxvalue);

    //Temparture
    expectedmaxvalue = 150;
    expectedminvalue = -50;
    obtainedminvalue = minValue(&Temperature[0]);
    obtainedmaxvalue = maxValue(&Temperature[0]);
    SMATemp = getSimpleMovingAverage(&Temperature[0]);

    printf("Temperature values from sender");
    printReceivedDataToConsole(Temperature);
    printf("The Minimum value of Temperature is %.2f \n",obtainedminvalue);
    printf("The Maximum value of Temperature is %.2f \n",obtainedmaxvalue);
    printf("The SMA of Temperature is %.2f \n",SMATemp);

    assert(obtainedminvalue >= expectedminvalue);
    assert(obtainedmaxvalue <= expectedmaxvalue);
    
}

int main(){
    Test_case1();
}
