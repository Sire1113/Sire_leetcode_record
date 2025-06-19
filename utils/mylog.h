//
// Created by Sire1 on 25-6-19.
//
#pragma once
#include <iostream>
#include <string>

class LOG{
public:
    static void info(const std::string& message);
    static void error(const std::string& message);
    static void warning(const std::string& message);
private:
    enum class log_level{
        INFO_LEVEL, WARNING_LEVEL, ERROR_LEVEL
    };

};
