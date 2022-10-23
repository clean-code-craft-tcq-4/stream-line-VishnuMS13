#define CATCH_CONFIG_MAIN
#include "../includes/Receiver.h"
#include <assert.h>

//Test the entries
Test1(){
    float Temperature[numberofreading] = {0};
    float Current[numberofreading]= {0};
    float obtainedminvalue, obtainedmaxvalue, obtainedSMA, expectedminvalue, expectedmaxvalue, expectedSMA;
    float expectedData [2][2] = {{-10,-46}, {9,-28}};
    expectedmaxvalue = 150;
    expectedminvalue = -50;
    expectedSMA = 11.6;
    receiveAndProcessSensorData(&Temperature[0],&Current[0]);
    for (int i= 0; i<2;i++){
        for(int j = 0; j<i ;j++)
        {
        REQUIRE(Current[j] == expectedData [j][j]);
        REQUIRE(Temperature[j] == expectedData [j][i]);
        }
    }
    REQUIRE(obtainedminvalue == expectedminvalue);
    REQUIRE(obtainedminvalue == expectedminvalue);
}

//Test Min, MAx and SMA
Test2(){
    float Temperature[numberofreading] = {0};
    float Current[numberofreading]= {0};
    float obtainedminvalue, obtainedmaxvalue, obtainedSMA, expectedminvalue, expectedmaxvalue, expectedSMA;
    //Temparture
    expectedmaxvalue = 150;
    expectedminvalue = -50;
    expectedSMA = 11.6;
    obtainedminvalue = minValue(&Temperature[0]);
    obtainedmaxvalue = maxValue(&Temperature[0]);
    obtainedSMA = getSimpleMovingAverage(&Temperature[0]);

    REQUIRE(obtainedminvalue == expectedminvalue);
    REQUIRE(obtainedmaxvalue == expectedmaxvalue);
    REQUIRE(obtainedSMA == expectedSMA);

    //Current
    expectedmaxvalue = 15;
    expectedminvalue = -15;
    expectedSMA = 5;
    obtainedminvalue = minValue(&Current[0]);
    obtainedmaxvalue = maxValue(&Current[0]);
    obtainedSMA = getSimpleMovingAverage(&Current[0]);

    REQUIRE(obtainedminvalue == expectedminvalue);
    REQUIRE(obtainedmaxvalue == expectedmaxvalue);
    REQUIRE(obtainedSMA == expectedSMA);
}

int main(void){
    Test1();
    Test2();
}
