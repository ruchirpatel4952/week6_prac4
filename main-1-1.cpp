#include <iostream>
#include <ctime>
#include <vector>
#include <memory>

class Vehicle {
private:
    std::time_t timeOfEntry;
    int ID;

public:
    Vehicle(int id) : ID(id) {
        timeOfEntry = std::time(nullptr);
    }

    int getID() const {
        return ID;
    }

    virtual int getParkingDuration() const {
        std::time_t currentTime = std::time(nullptr);
        return static_cast<int>(currentTime - timeOfEntry);
    }
};

class Car : public Vehicle {
public:
    Car(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int baseDuration = Vehicle::getParkingDuration();
        return static_cast<int>(baseDuration * 0.9);
    }
};

class Bus : public Vehicle {
public:
    Bus(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int baseDuration = Vehicle::getParkingDuration();
        return static_cast<int>(baseDuration * 0.75);
    }
};

class Motorbike : public Vehicle {
public:
    Motorbike(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int baseDuration = Vehicle::getParkingDuration();
        return static_cast<int>(baseDuration * 0.85);
    }
};

int main() {
    int numCars, numBuses, numMotorbikes;

    std::cout << "Enter the number of cars: ";
    std::cin >> numCars;
    std::cout << "Enter the number of buses: ";
    std::cin >> numBuses;
    std::cout << "Enter the number of motorbikes: ";
    std::cin >> numMotorbikes;

    std::vector<std::unique_ptr<Vehicle>> vehicles;

    for (int i = 1; i <= numCars; ++i) {
        vehicles.push_back(std::make_unique<Car>(i));
    }

    for (int i = 1; i <= numBuses; ++i) {
        vehicles.push_back(std::make_unique<Bus>(i));
    }

    for (int i = 1; i <= numMotorbikes; ++i) {
        vehicles.push_back(std::make_unique<Motorbike>(i));
    }

    std::cout << "\nParking Durations:\n";
    for (const auto& vehicle : vehicles) {
        std::cout << "Vehicle ID: " << vehicle->getID() << " - Parking Duration: " << vehicle->getParkingDuration() << " seconds\n";
    }

    return 0;
}
