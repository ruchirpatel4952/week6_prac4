#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
    int capacity = 10; // Set the capacity of the parking lot

    ParkingLot parkingLot(capacity); // Create a parking lot object

    // Park vehicles in the parking lot until it's full
    while (parkingLot.getCount() < capacity) {
        int vehicleType;
        int vehicleID;

        std::cout << "Enter the vehicle type (1 for Car, 2 for Bus, 3 for Motorbike): ";
        std::cin >> vehicleType;

        std::cout << "Enter the vehicle ID: ";
        std::cin >> vehicleID;

        Vehicle* vehicle;
        if (vehicleType == 1) {
            vehicle = new Car(vehicleID);
        } else if (vehicleType == 2) {
            vehicle = new Bus(vehicleID);
        } else if (vehicleType == 3) {
            vehicle = new Motorbike(vehicleID);
        } else {
            std::cout << "Invalid vehicle type." << std::endl;
            continue;
        }

        if (!parkingLot.parkVehicle(vehicle)) {
            std::cout << "The parking lot is full" << std::endl;
            delete vehicle; // Clean up the dynamically allocated memory
        }
    }

    // Count overstaying vehicles with a max parking duration of 15 seconds
    int maxParkingDuration = 15;
    int overstayingCount = parkingLot.countOverstayingVehicles(maxParkingDuration);

    std::cout << "Number of vehicles overstaying: " << overstayingCount << std::endl;

    // Clean up dynamically allocated memory
    parkingLot.~ParkingLot();

    return 0;
}
