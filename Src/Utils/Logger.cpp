#include "Logger.h"
#include <chrono>
#include <ctime>

void Write(Level level, std::string caller, std::string message)
{
    std::string color;
    /*auto start = std::chrono::system_clock::now();

    auto currentTime = std::chrono::system_clock::to_time_t(start);
    tm* tm1 = std::localtime(&currentTime);
    char* tmBuff = std:asctime_s(localtime(&currentTime));
    char timeFormat[] = "hh:mm:ss";
    std::size_t time = std::strftime(tmBuff, (long long) sizeof(tmBuff), (char*) timeFormat, tm1);*/

    std::string time = "not implemented";
    std::string levelName;
    
    switch (level)
    {
    case Debug:
        color = "\43";
        levelName = "DEBUG";
        break;
    case Info:
        color = "\104";
        levelName = "INFO";
        break;
    case Warning:
        color = "\103";
        levelName = "WARNING";
        break;
    case Error:
        color = "\101";
        levelName = "ERROR";
        break;
    case Fatal:
        color = "\41";
        levelName = "FATAL";
        break;
    default:
        color = "";
        levelName = "";
        break;
    }

    std::string formatted = std::format("{}[{}] [{}] [{}]: {}", color, caller, levelName, time, message);

    std::cout << formatted << std::endl;
}