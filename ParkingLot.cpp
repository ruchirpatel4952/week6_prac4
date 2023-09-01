#include "ParkingLot.h"
#include <algorithm>

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity), currentCount(0) {
    // Initialize the parking lot with a given capacity
    vehicles.reserve(maxCapacity);
}

ParkingLot::~ParkingLot() {
    // Clean up dynamically allocated memory for parked vehicles
    clear();
}

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (currentCount < maxCapacity) {
        vehicles.push_back(vehicle);
        currentCount++;
        return true;
    } else {
        return false; // Parking lot is full
    }
}

bool ParkingLot::unparkVehicle(int vehicleID) {
    auto it = std::remove_if(vehicles.begin(), vehicles.end(),
                             [vehicleID](Vehicle* vehicle) {
                                 return vehicle->getID() == vehicleID;
                             });

    if (it != vehicles.end()) {
        delete *it; // Clean up the memory of the removed vehicle
        vehicles.erase(it, vehicles.end());
        currentCount--;
        return true;
    } else {
        return false; // Vehicle not found in the parking lot
    }
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int overstayingCount = 0;
    std::time_t currentTime = std::time(nullptr);

    for (const auto& vehicle : vehicles) {
        int parkingDuration = vehicle->getParkingDuration();
        if (parkingDuration > maxParkingDuration) {
            overstayingCount++;
        }
    }

    return overstayingCount;
}

int ParkingLot::getCount() const {
    return currentCount;
}

void ParkingLot::clear() {
    // Clean up dynamically allocated memory for all parked vehicles
    for (const auto& vehicle : vehicles) {
        delete vehicle;
    }

    vehicles.clear();
    currentCount = 0;
}
