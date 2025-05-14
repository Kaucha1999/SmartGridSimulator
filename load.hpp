#ifndef LOAD_HPP
#define LOAD_HPP

#include <string>

class Load {
private:
    std::string name;
    float demand;
    bool active;

public:
    Load(std::string name, float demand);
    float getDemand() const;
    std::string getName() const;
    bool isActive() const;
    void disconnect();
    void reconnect();
};

#endif
