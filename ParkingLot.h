#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include "Vehicle.h"

class ParkingLot {
private:
    int maxCapacity;
    int currentCount;
    std::vector<Vehicle*> vehicles;

public:
    ParkingLot(int capacity);
    ~ParkingLot();

    bool parkVehicle(Vehicle* vehicle);
    bool unparkVehicle(int vehicleID);
    int countOverstayingVehicles(int maxParkingDuration) const;
    int getCount() const;
    void clear(); // Declare the clear function
};

#endif // PARKINGLOT_H
