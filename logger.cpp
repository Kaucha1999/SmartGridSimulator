#include "logger.hpp"
#include <ctime>

Logger::Logger(const std::string& filename) {
    file.open(filename, std::ios::app);
}

Logger::~Logger() {
    file.close();
}

void Logger::log(const std::string& message) {
    std::time_t now = std::time(nullptr);
    file << std::ctime(&now) << " - " << message << "\n";
}
