#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    int numCars, numBuses, numMotorbikes;

    std::cout << "Enter the number of cars: ";
    std::cin >> numCars;
    std::cout << "Enter the number of buses: ";
    std::cin >> numBuses;
    std::cout << "Enter the number of motorbikes: ";
    std::cin >> numMotorbikes;

    std::vector<Vehicle*> vehicles;

    for (int i = 1; i <= numCars; ++i) {
        vehicles.push_back(new Car(i));
    }

    for (int i = 1; i <= numBuses; ++i) {
        vehicles.push_back(new Bus(i));
    }

    for (int i = 1; i <= numMotorbikes; ++i) {
        vehicles.push_back(new Motorbike(i));
    }

    std::cout << "\nParking Durations:\n";
    for (const auto& vehicle : vehicles) {
        std::cout << "Vehicle ID: " << vehicle->getID() << " - Parking Duration: " << vehicle->getParkingDuration() << " seconds\n";
    }

    // Clean up dynamically allocated memory
    for (const auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
