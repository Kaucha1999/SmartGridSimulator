#ifndef POWER_SOURCE_HPP
#define POWER_SOURCE_HPP

#include <string>

class PowerSource {
private:
    std::string name;
    float maxCapacity;
    float currentOutput;

public:
    PowerSource(std::string name, float maxCap);
    void generate();
    float getOutput() const;
    std::string getName() const;
};

#endif
