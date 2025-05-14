#include "grid_manager.hpp"
#include <iostream>

GridManager::GridManager() : logger("logs/event_log.txt") {}

void GridManager::addSource(const PowerSource& source) {
    sources.push_back(source);
}

void GridManager::addBreaker(const Breaker& breaker) {
    breakers.push_back(breaker);
}

void GridManager::simulateCycle() {
    float totalSupply = 0.0f;

    for (auto& s : sources) {
        s.generate();
        totalSupply += s.getOutput();
    }

    logger.log("Total power generated: " + std::to_string(totalSupply) + " kW");

    for (auto& b : breakers) {
        b.check(totalSupply);
        Load* l = b.getLoad();
        if (b.isTripped()) {
            logger.log("Breaker tripped for load: " + l->getName());
        } else {
            totalSupply -= l->getDemand();
        }
    }
}

void GridManager::showStatus() {
    std::cout << "\n---- Grid Status ----\n";
    for (auto& s : sources) {
        std::cout << "Source: " << s.getName() << " Output: " << s.getOutput() << " kW\n";
    }
    for (auto& b : breakers) {
        Load* l = b.getLoad();
        std::cout << "Load: " << l->getName() 
                  << " Demand: " << l->getDemand() 
                  << " Status: " << (b.isTripped() ? "TRIPPED" : "ACTIVE") << "\n";
    }
}

void GridManager::resetAllBreakers() {
    for (auto& b : breakers) {
        b.reset();
    }
    logger.log("All breakers reset.");
}
