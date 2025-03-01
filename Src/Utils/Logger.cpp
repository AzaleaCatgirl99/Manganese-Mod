#include "Logger.h"
#include <chrono>
#include <ctime>

void Write(LoggerLevel level, std::string caller, std::string message)
{
    std::string color;
    std::string time = "not implemented";
    std::string levelName;
    
    switch (level)
    {
    case Debug:
        color = "43";
        levelName = "DEBUG";
        break;
    case Info:
        color = "104";
        levelName = "INFO";
        break;
    case Warning:
        color = "103";
        levelName = "WARNING";
        break;
    case Error:
        color = "101";
        levelName = "ERROR";
        break;
    case Fatal:
        color = "41";
        levelName = "FATAL";
        break;
    default:
        color = "0";
        levelName = "";
        break;
    }

    std::string formatted = std::format("[{}] [{}]: {}", caller, levelName, message);

    std::cout << "\033[" << color << "m" << formatted << std::endl;
}