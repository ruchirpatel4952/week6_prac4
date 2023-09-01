#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
    int capacity = 10; // Set the capacity of the parking lot

    ParkingLot parkingLot(capacity); // Create a parking lot object

    // Prompt the user for vehicle types and IDs and park them until the lot is full
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

        parkingLot.parkVehicle(vehicle);
    }

    // Prompt the user for a vehicle ID to unpark and remove it from the lot
    int vehicleToUnpark;
    std::cout << "Enter the vehicle ID to unpark: ";
    std::cin >> vehicleToUnpark;

    parkingLot.unparkVehicle(vehicleToUnpark);

    // Clean up dynamically allocated memory
    parkingLot.~ParkingLot();

    return 0;
}
