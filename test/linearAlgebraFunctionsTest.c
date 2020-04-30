#include "../src/LinearAlgebraFunctions.h"
#include <gtest/gtest.h>

TEST(addArraysTest, addArrays){

    double a[3] = {1.0, 2.0, 3.0};

    EXPECT_EQ([ 1.0 + 1.0, 2.0 + 2.0, 3.0 + 30], addArrays(3, a, a));
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}