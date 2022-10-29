#include "includes/Receiver.h"
#include <assert.h>

//Check if min and max values are within limits and display on the console
void Test_case1(){
    float Temperature[numberofreading] = {0};
    float Current[numberofreading]= {0};
    float obtainedminvalue, obtainedmaxvalue, obtainedSMA, expectedminvalue, expectedmaxvalue, expectedSMA;
    //Temparture
    expectedmaxvalue = 150;
    expectedminvalue = -50;
    obtainedminvalue = minValue(&Temperature[0]);
    obtainedmaxvalue = maxValue(&Temperature[0]);
    printf("The Minimum value of Temperature is %f",&obtainedminvalue);
    printf("The Maximum value of Temperature is %f",&obtainedmaxvalue);
    assert(obtainedminvalue >= expectedminvalue);
    assert(obtainedmaxvalue <= expectedmaxvalue);

    //Current
    expectedmaxvalue = 15;
    expectedminvalue = -15;
    obtainedminvalue = minValue(&Current[0]);
    obtainedmaxvalue = maxValue(&Current[0]);
    printf("The Minimum value of Current is %f",&obtainedminvalue);
    printf("The Maximum value of Current is %f",&obtainedmaxvalue);

    assert(obtainedminvalue >= expectedminvalue);
    assert(obtainedmaxvalue <= expectedmaxvalue);
}

void Test_case2(){
    //Print the obtained SMA values of the Sensor Data
    float Temperature[numberofreading] = {0};
    float Current[numberofreading]= {0};
    receiveAndProcessSensorData(&Temperature[0],&Current[0]);
    // Get the SMA of Temperature
    float SMATemp = getSimpleMovingAverage(&Temperature[0]);
    printf("The SMA of Temperature is %f",&SMATemp);
    // Get the SMA of Current
    float SMACurrent = getSimpleMovingAverage(&Current[0]);
    printf("The SMA of Temperature is %f",&SMACurrent);
}

int main(){
    Test_case1();
    Test_case2();
}
