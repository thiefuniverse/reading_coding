#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "flyconfig.h"



namespace FlyConfigNamespace{

bool FlyConfig::loadConfig(std::string config_file){
    std::ifstream readConfig(config_file);
    std::string line;
    while(std::getline(readConfig,line)){
        addOneConfigPiece(line);
    }
}

// decode config line to key, datatype, value
std::shared_ptr<FlyConfigPiece> FlyConfig::decodeConfigLine(std::string config_line, std::string& key){

    if (config_line.empty()){
        return nullptr;
    }
    int flag=0;
    // jump start spaces
    for(; flag< config_line.size(); flag++){
        if (config_line[flag] != ' '){
            break;
        }
    }

    // get config key name
    std::string firstKey;
    for(; flag< config_line.size(); flag++){
        if (config_line[flag] != ' '){
            firstKey += config_line[flag];
        }
        else{
            break;
        }
    }

    // get data type
    std::string dataType;
    for(; flag< config_line.size(); flag++){
        if (config_line[flag] != ' '){
            dataType += config_line[flag];
            if (flag+1 < config_line.size() && config_line[flag+1] != ' '){
                std::cout<<"error: config type not defined.\n";
                return nullptr;
            }
            break;
        }
    }

    // get value
    std::cout<< "key: *"<<firstKey<<"*"<<std::endl;
    std::cout<< "dataType: *"<<dataType<<"*"<<std::endl;
    std::string valTemp = config_line.substr(flag+1, config_line.size()-flag);
    int startPoint = valTemp.find_first_not_of(" ");
    int endPoint = valTemp.find_last_not_of(" ");
    std::string valueStr = valTemp.substr(startPoint, endPoint - startPoint + 1);

    std::cout<< "value: *"<<valTemp<<"*"<<std::endl;
    std::cout<< "valueStr"<<valueStr<<std::endl;
    std::cout<< "startPoint"<<startPoint<<std::endl;
    std::cout<< "endPoint"<<endPoint<<std::endl;

    key = firstKey;
    return constructConfigPiece(dataType, valueStr);
}

std::shared_ptr<FlyConfigPiece> FlyConfig::constructConfigPiece(std::string& datatype, std::string& value){
    if (!configType[datatype]){
        std::cout<<"config type not supported."<<std::endl;
        return nullptr;
    }

    return std::make_shared<FlyConfigPiece>(datatype,value);
}

void FlyConfig::addOneConfigPiece(std::string config_line){
    // ignore empty line
    if (config_line.empty()){
        return;
    }

    // ignore comments
    if (config_line[0] == '#'){
        return;
    }

    std::string key;
    std::shared_ptr<FlyConfigPiece> one = decodeConfigLine(config_line, key);
    if (one){
        allConfigs[key] = one;
    }

}
};