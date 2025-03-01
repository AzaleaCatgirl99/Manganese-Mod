#pragma once
#include <string>
#include <iostream>

enum LoggerLevel
{
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};

void Write(LoggerLevel level, std::string caller, std::string message);