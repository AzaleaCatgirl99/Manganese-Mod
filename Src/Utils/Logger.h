#ifndef LOGGER_H
#define LOGGER_H
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

#endif
