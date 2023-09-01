#include "Motorbike.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    int baseDuration = Vehicle::getParkingDuration();
    return static_cast<int>(baseDuration * 0.85);
}
