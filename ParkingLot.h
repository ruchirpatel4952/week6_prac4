#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"

class ParkingLot {
private:
    int maxCapacity;
    int currentCount;
    Vehicle** vehicles;

public:
    ParkingLot(int capacity);
    ~ParkingLot();

    bool parkVehicle(Vehicle* vehicle);
    bool unparkVehicle(int vehicleID);
    int getCount() const;
};

#endif // PARKINGLOT_H
