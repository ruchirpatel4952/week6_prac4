#include <iostream>
#include <ctime>
#include <vector>
#include <memory>

class Vehicle {
private:
    std::time_t timeOfEntry;
    int ID;

public:
    Vehicle(int id) : ID(id) {
        timeOfEntry = std::time(nullptr);
    }

    int getID() const {
        return ID;
    }

    int getParkingDuration() const {
        std::time_t currentTime = std::time(nullptr);
        return static_cast<int>(currentTime - timeOfEntry);
    }
};

class Car : public Vehicle {
public:
    Car(int id) : Vehicle(id) {}

    int getParkingDuration() const {
        int baseDuration = Vehicle::getParkingDuration();
        return static_cast<int>(baseDuration * 0.9);
    }
};

class Bus : public Vehicle {
public:
    Bus(int id) : Vehicle(id) {}

    int getParkingDuration() const {
        int baseDuration = Vehicle::getParkingDuration();
        return static_cast<int>(baseDuration * 0.75);
    }
};

class Motorbike : public Vehicle {
public:
    Motorbike(int id) : Vehicle(id) {}

    int getParkingDuration() const {
        int baseDuration = Vehicle::getParkingDuration();
        return static_cast<int>(baseDuration * 0.85);
    }
};

class ParkingLot {
private:
    int maxCapacity;
    int count;
    std::vector<std::unique_ptr<Vehicle>> vehicles;

public:
    ParkingLot(int capacity) : maxCapacity(capacity), count(0) {
        vehicles.reserve(maxCapacity);
    }

    int getCount() const {
        return count;
    }

    void parkVehicle(std::unique_ptr<Vehicle> vehicle) {
        if (count < maxCapacity) {
            vehicles.push_back(std::move(vehicle));
            count++;
            std::cout << "Vehicle parked successfully.\n";
        } else {
            std::cout << "The lot is full.\n";
        }
    }

    void unparkVehicle(int id) {
        auto it = std::remove_if(vehicles.begin(), vehicles.end(),
            [id](const std::unique_ptr<Vehicle>& v) { return v->getID() == id; });

        if (it != vehicles.end()) {
            vehicles.erase(it, vehicles.end());
            count--;
            std::cout << "Vehicle with ID " << id << " unparked successfully.\n";
        } else {
            std::cout << "Vehicle not in the lot.\n";
        }
    }

    int countOverstayingVehicles(int maxParkingDuration) {
        int overstayingCount = 0;
        for (const auto& vehicle : vehicles) {
            if (vehicle->getParkingDuration() > maxParkingDuration) {
                overstayingCount++;
            }
        }
        return overstayingCount;
    }
};

int main() {
    ParkingLot parkingLot(10);

    while (parkingLot.getCount() < 10) {
        std::cout << "Enter the type of vehicle (1 - Car, 2 - Bus, 3 - Motorbike): ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            parkingLot.parkVehicle(std::make_unique<Car>(parkingLot.getCount() + 1));
        } else if (choice == 2) {
            parkingLot.parkVehicle(std::make_unique<Bus>(parkingLot.getCount() + 1));
        } else if (choice == 3) {
            parkingLot.parkVehicle(std::make_unique<Motorbike>(parkingLot.getCount() + 1));
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    int maxParkingDuration = 15;
    int overstayingCount = parkingLot.countOverstayingVehicles(maxParkingDuration);

    std::cout << "Number of vehicles overstaying for more than " << maxParkingDuration << " seconds: " << overstayingCount << "\n";

    return 0;
}
