//
// Created by Sire1 on 25-6-19.
//
#include "mylog.h"
void LOG::info(const std::string& message){
    std::cout << "[INFO] " << message << std::endl;
}
void LOG::error(const std::string& message) {
    std::cout << "[ERROR] " << message << std::endl;
}
void LOG::warning(const std::string& message) {
    std::cout << "[WARNING] " << message << std::endl;
}
