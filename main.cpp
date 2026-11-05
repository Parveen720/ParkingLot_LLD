#include <iostream>

#include "ParkingLot.h"
#include "ParkingManager.h"

#include "models/Car.h"
#include "models/Motorcycle.h"
#include "models/Truck.h"

using namespace std;

int main() {

    // Create parking lot
    ParkingLot parkingLot("City Parking");

    // Add floors
    parkingLot.addFloor(1);
    parkingLot.addFloor(2);

    // Add spots on floor 1
    parkingLot.addParkingSpot(
        1, 101, VehicleType::MOTORCYCLE
    );

    parkingLot.addParkingSpot(
        1, 102, VehicleType::CAR
    );

    parkingLot.addParkingSpot(
        1, 103, VehicleType::CAR
    );

    // Add spots on floor 2
    parkingLot.addParkingSpot(
        2, 201, VehicleType::TRUCK
    );

    parkingLot.addParkingSpot(
        2, 202, VehicleType::CAR
    );

    parkingLot.addParkingSpot(
        2, 203, VehicleType::MOTORCYCLE
    );

    // Create manager
    ParkingManager manager(parkingLot);

    // Create vehicle objects
    Car car("RJ14AB1234");

    Motorcycle bike("RJ14CD5678");

    Truck truck("RJ14EF9012");

    // Park vehicles
    cout << "\n========== PARK VEHICLES ==========\n";

    manager.parkVehicle(&car);
    manager.parkVehicle(&bike);
    manager.parkVehicle(&truck);

    // Display active tickets
    cout << "\n========== ACTIVE TICKETS ==========\n";

    manager.displayActiveTickets();

    // Unpark vehicles
    cout << "\n========== UNPARK VEHICLES ==========\n";

    manager.unparkVehicle("T1");
    manager.unparkVehicle("T2");

    // Display remaining tickets
    cout << "\n========== REMAINING TICKETS ==========\n";

    manager.displayActiveTickets();

    return 0;
}