#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity), currentCount(0) {
    vehicles = new Vehicle*[maxCapacity];
}

ParkingLot::~ParkingLot() {
    for (int i = 0; i < currentCount; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;
}

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (currentCount < maxCapacity) {
        vehicles[currentCount++] = vehicle;
        return true; // Vehicle parked successfully
    } else {
        std::cout << "The parking lot is full" << std::endl;
        return false; // Parking lot is full
    }
}

bool ParkingLot::unparkVehicle(int vehicleID) {
    for (int i = 0; i < currentCount; ++i) {
        if (vehicles[i]->getID() == vehicleID) {
            delete vehicles[i];
            vehicles[i] = vehicles[currentCount - 1];
            currentCount--;
            return true; // Vehicle removed successfully
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
    return false; // Vehicle not found in the parking lot
}

int ParkingLot::getCount() const {
    return currentCount;
}
#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity), currentCount(0) {
    vehicles = new Vehicle*[maxCapacity];
}

ParkingLot::~ParkingLot() {
    for (int i = 0; i < currentCount; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;
}

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (currentCount < maxCapacity) {
        vehicles[currentCount++] = vehicle;
        return true; // Vehicle parked successfully
    } else {
        std::cout << "The parking lot is full" << std::endl;
        return false; // Parking lot is full
    }
}

bool ParkingLot::unparkVehicle(int vehicleID) {
    for (int i = 0; i < currentCount; ++i) {
        if (vehicles[i]->getID() == vehicleID) {
            delete vehicles[i];
            vehicles[i] = vehicles[currentCount - 1];
            currentCount--;
            return true; // Vehicle removed successfully
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
    return false; // Vehicle not found in the parking lot
}

int ParkingLot::getCount() const {
    return currentCount;
}
