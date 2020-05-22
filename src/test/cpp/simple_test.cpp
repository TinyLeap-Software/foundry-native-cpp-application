#include "gtest/gtest.h"

TEST(SIMPLE_TEST, test_initialize) {
    int sum=10+10;
    if(sum==20){
        SUCCEED();
    }else{
        FAIL();
    }
}