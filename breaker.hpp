#ifndef BREAKER_HPP
#define BREAKER_HPP

#include "load.hpp"

class Breaker {
private:
    Load* load;
    bool tripped;

public:
    Breaker(Load* load);
    void check(float supplyAvailable);
    void reset();
    bool isTripped() const;
    Load* getLoad() const;
};

#endif
