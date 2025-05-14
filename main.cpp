#include <iostream>
#include <vector>
#include <memory>
#include "load.hpp"
#include "breaker.hpp"
#include "power_source.hpp"
#include "grid_manager.hpp"

int main() {
    GridManager manager;
    std::vector<std::unique_ptr<Load>> loads;
    std::vector<std::unique_ptr<Breaker>> breakers;

    int choice;
    while (true) {
        std::cout << "\n=== SMART GRID SIMULATOR ===\n";
        std::cout << "1. Add Power Source\n";
        std::cout << "2. Add Load\n";
        std::cout << "3. Simulate Cycle\n";
        std::cout << "4. Show Grid Status\n";
        std::cout << "5. Reset All Breakers\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            float capacity;
            std::cout << "Enter source name: ";
            std::cin >> name;
            std::cout << "Enter max capacity (kW): ";
            std::cin >> capacity;
            manager.addSource(PowerSource(name, capacity));
        }

        else if (choice == 2) {
            std::string name;
            float demand;
            std::cout << "Enter load name: ";
            std::cin >> name;
            std::cout << "Enter demand (kW): ";
            std::cin >> demand;

            auto load = std::make_unique<Load>(name, demand);
            auto breaker = std::make_unique<Breaker>(load.get());
            manager.addBreaker(*breaker);

            breakers.push_back(std::move(breaker));
            loads.push_back(std::move(load));
        }

        else if (choice == 3) {
            manager.simulateCycle();
        }

        else if (choice == 4) {
            manager.showStatus();
        }

        else if (choice == 5) {
            manager.resetAllBreakers();
        }

        else if (choice == 6) {
            std::cout << "Exiting...\n";
            break;
        }

        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
