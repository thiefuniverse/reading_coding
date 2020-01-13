#include "version.h"
#include <iostream>
#include "gtest/gtest.h"

using namespace base;
TEST(test_version, out){
    Version ver("2.1.0");
    std::cout<< ver<<std::endl;
}