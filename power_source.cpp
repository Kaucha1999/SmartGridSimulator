#include "power_source.hpp"
#include <cstdlib>
#include <ctime>

PowerSource::PowerSource(std::string name, float maxCap)
    : name(name), maxCapacity(maxCap), currentOutput(0) {
    std::srand(std::time(0));
}

void PowerSource::generate() {
    float factor = 0.5f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 0.5f));
    currentOutput = maxCapacity * factor;
}

float PowerSource::getOutput() const {
    return currentOutput;
}

std::string PowerSource::getName() const {
    return name;
}
