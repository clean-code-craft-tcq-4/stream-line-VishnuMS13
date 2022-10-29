#include "includes/Receiver.h"
#include <assert.h>

//Test the entries
void Test_case1(){
    float Temperature[numberofreading] = {0};
    float Current[numberofreading]= {0};
    float expectedData [2][2] = {{-10,-46}, {9,-28}};
    receiveAndProcessSensorData(&Temperature[0],&Current[0]);
    for (int i= 0; i<2;i++){
        {
        assert(Current[i] == expectedData [i][0]);
        assert(Temperature[i] == expectedData [i][1]);
        }
    }
}

//Test Min, MAx and SMA
void Test_case2(){
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

    assert(obtainedminvalue == expectedminvalue);
    assert(obtainedmaxvalue == expectedmaxvalue);
    assert(obtainedSMA == expectedSMA);

    //Current
    expectedmaxvalue = 15;
    expectedminvalue = -15;
    expectedSMA = 5;
    obtainedminvalue = minValue(&Current[0]);
    obtainedmaxvalue = maxValue(&Current[0]);
    obtainedSMA = getSimpleMovingAverage(&Current[0]);

    assert(obtainedminvalue == expectedminvalue);
    assert(obtainedmaxvalue == expectedmaxvalue);
    assert(obtainedSMA == expectedSMA);
}

int main(){
    Test_case1();
    Test_case2();
}
