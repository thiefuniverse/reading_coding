// # flyconfig:  A lib for managing config file by C++

// * requirements:

// ** data type supported: string, int, float
// ** comment (start with '#')
// ** config format: key(config name) type_flag(s,i,f) value(config value) 
// ** if it's not comment, the first word is key and second word is type flag, 
//    rest is value whose spaces will be ignored.
// ** for type_flag, s means string, i means int and f means float.
// ** ignore empty line and comments.


// * example:

// ``` a.flyconfig

// # it's user's name
// user_name s Thank Fly
// user_age i 21
// user_height f 170.3

// ```

// this config will function like this.

// ``` c++
// FlyConfig config("a.flyconfig");
// string un = config.get("user_name");   // un: "Thank Fly"
// int    ua = config.get("user_age");    // ua: 21
// float  uh = config.get("user_height"); // uh: 170.3
// ```

#include<string>
#include<map>
#include<memory>
#include <iostream>

namespace FlyConfigNamespace{

struct FlyConfigPiece{
    public:

        FlyConfigPiece(std::string dt, std::string val):datatype(dt),value(val){
        }
        int toInt(){
            if (datatype != "i"){
                std::cout<< "you try to convert it to int. it may be wrong."<<std::endl;
            }
            return std::atoi(value.c_str());
        }
        float toFloat(){
            if (datatype != "f"){
                std::cout<< "you try to convert it to float. it may be wrong."<<std::endl;
            }
            return std::atof(value.c_str());
        }
        std::string toStr(){
            if (datatype != "s"){
                std::cout<< "you try to convert it to string. it may be wrong."<<std::endl;
            }
            return value;
        }
    private:
        std::string datatype;
        std::string value;
};

class FlyConfig{
    public:
        std::map<std::string, bool> configType{{"s",true}, {"i",true}, {"f",true}};
        FlyConfig(){};
        FlyConfig(std::string config_file){
            loadConfig(config_file);
        }
        std::map<std::string, std::shared_ptr<FlyConfigPiece>> & getAllConfigs(){
            return allConfigs;
        }

    private:
        bool loadConfig(std::string config_file);
        std::shared_ptr<FlyConfigPiece> decodeConfigLine(std::string config_line, std::string& key);
        std::shared_ptr<FlyConfigPiece> constructConfigPiece(std::string& datatype, std::string& value);
        void addOneConfigPiece(std::string config_line);
    private:
        std::map<std::string, std::shared_ptr<FlyConfigPiece>> allConfigs;
        
};
}