#include <iostream>
#include "callback.h"
#include "bind.h"
#include "gtest/gtest.h"

using namespace base;

int Return1 () {
    return 1;
}
TEST(test_callback, out){
    base::OnceCallback<int()> fc = base::BindOnce(&Return1);
    std::cout<<std::move(fc).Run()<<std::endl;
    
}