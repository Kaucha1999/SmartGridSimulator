#ifndef GRID_MANAGER_HPP
#define GRID_MANAGER_HPP

#include <vector>
#include "power_source.hpp"
#include "breaker.hpp"
#include "logger.hpp"

class GridManager {
private:
    std::vector<PowerSource> sources;
    std::vector<Breaker> breakers;
    Logger logger;

public:
    GridManager();
    void addSource(const PowerSource&);
    void addBreaker(const Breaker&);
    void simulateCycle();
    void showStatus();
    void resetAllBreakers();
};

#endif
