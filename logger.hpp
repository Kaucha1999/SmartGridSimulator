#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

class Logger {
private:
    std::ofstream file;

public:
    Logger(const std::string& filename);
    ~Logger();
    void log(const std::string& message);
};

#endif
