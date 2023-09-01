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

    int choice;
    while (true) {
        std::cout << "\nSelect an option:\n";
        std::cout << "1. Park a vehicle\n";
        std::cout << "2. Unpark a vehicle\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int vehicleType, vehicleID;
            std::cout << "\nSelect a vehicle type:\n";
            std::cout << "1. Car\n";
            std::cout << "2. Bus\n";
            std::cout << "3. Motorbike\n";
            std::cout << "Enter your choice: ";
            std::cin >> vehicleType;

            std::cout << "Enter vehicle ID: ";
            std::cin >> vehicleID;

            Vehicle* vehicle;
            if (vehicleType == 1) {
                vehicle = new Car(vehicleID);
            } else if (vehicleType == 2) {
                vehicle = new Bus(vehicleID);
            } else if (vehicleType == 3) {
                vehicle = new Motorbike(vehicleID);
            } else {
                std::cout << "Invalid vehicle type.\n";
                continue;
            }

            if (parkingLot.parkVehicle(vehicle)) {
                std::cout << "Vehicle with ID " << vehicleID << " parked successfully.\n";
            } else {
                std::cout << "The parking lot is full. Cannot park the vehicle.\n";
                delete vehicle; // Clean up the dynamically allocated memory
            }
        } else if (choice == 2) {
            int vehicleID;
            std::cout << "Enter vehicle ID to unpark: ";
            std::cin >> vehicleID;

            if (parkingLot.unparkVehicle(vehicleID)) {
                std::cout << "Vehicle with ID " << vehicleID << " has been unparked.\n";
            } else {
                std::cout << "Vehicle with ID " << vehicleID << " is not in the parking lot.\n";
            }
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
