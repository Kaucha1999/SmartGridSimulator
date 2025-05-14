#include "load.hpp"

Load::Load(std::string name, float demand)
    : name(name), demand(demand), active(true) {}

float Load::getDemand() const {
    return active ? demand : 0.0f;
}

std::string Load::getName() const {
    return name;
}

bool Load::isActive() const {
    return active;
}

void Load::disconnect() {
    active = false;
}

void Load::reconnect() {
    active = true;
}
