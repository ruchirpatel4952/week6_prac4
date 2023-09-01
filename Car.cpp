#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    int baseDuration = Vehicle::getParkingDuration();
    return static_cast<int>(baseDuration * 0.9);
}
