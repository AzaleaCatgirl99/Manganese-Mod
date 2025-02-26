#pragma once
#include <string>
#include <iostream>

enum Level
{
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};

void Write(Level level, std::string caller, std::string message);