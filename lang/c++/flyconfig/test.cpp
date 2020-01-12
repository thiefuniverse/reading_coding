#include "flyconfig.h"

using namespace FlyConfigNamespace;

#include <iostream>
 
int main (){
    FlyConfig config("a.flyconfig");
    auto m = config.getAllConfigs()["user_name"];
    std::cout<<config.getAllConfigs()["user_name"]->toStr()<<std::endl;
    std::cout<<config.getAllConfigs()["user_age"]->toInt()<<std::endl;
    std::cout<<config.getAllConfigs()["user_height"]->toFloat()<<std::endl;
    


    
}