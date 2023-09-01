#include "Vehicle.h"
#include <ctime>

Vehicle::Vehicle(int id) : ID(id) {
    timeOfEntry = std::time(nullptr);
}

int Vehicle::getID() const {
    return ID;
}

int Vehicle::getParkingDuration() const {
    std::time_t currentTime = std::time(nullptr);
    return static_cast<int>(currentTime - timeOfEntry);
}
