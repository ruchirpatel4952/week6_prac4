#include "Bus.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    int baseDuration = Vehicle::getParkingDuration();
    return static_cast<int>(baseDuration * 0.75);
}
