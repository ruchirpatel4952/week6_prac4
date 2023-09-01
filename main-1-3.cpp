#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
    int capacity;
    std::cout << "Enter the capacity of the parking lot: ";
    std::cin >> capacity;

    ParkingLot parkingLot(capacity);

    int numCars, numBuses, numMotorbikes;
    std::cout << "Enter the number of cars to park: ";
    std::cin >> numCars;
    std::cout << "Enter the number of buses to park: ";
    std::cin >> numBuses;
    std::cout << "Enter the number of motorbikes to park: ";
    std::cin >> numMotorbikes;

    for (int i = 1; i <= numCars; ++i) {
        Car* car = new Car(i);
        parkingLot.parkVehicle(car);
    }

    for (int i = 1; i <= numBuses; ++i) {
        Bus* bus = new Bus(i);
        parkingLot.parkVehicle(bus);
    }

    for (int i = 1; i <= numMotorbikes; ++i) {
        Motorbike* motorbike = new Motorbike(i);
        parkingLot.parkVehicle(motorbike);
    }

    std::cout << "\nCounting overstaying vehicles:\n";
    int maxParkingDuration;
    std::cout << "Enter the maximum allowed parking duration (in seconds): ";
    std::cin >> maxParkingDuration;

    int overstayingCount = parkingLot.countOverstayingVehicles(maxParkingDuration);
    std::cout << "Number of vehicles overstaying: " << overstayingCount << "\n";

    // Clean up dynamically allocated memory
    parkingLot.clear();

    return 0;
}
