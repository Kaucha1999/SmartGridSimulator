#include "breaker.hpp"

Breaker::Breaker(Load* load) : load(load), tripped(false) {}

void Breaker::check(float supplyAvailable) {
    if (load->getDemand() > supplyAvailable) {
        tripped = true;
        load->disconnect();
    }
}

void Breaker::reset() {
    tripped = false;
    load->reconnect();
}

bool Breaker::isTripped() const {
    return tripped;
}

Load* Breaker::getLoad() const {
    return load;
}
