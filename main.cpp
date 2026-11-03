#include <iostream>
#include <memory>

#include "ParkingLot.h"
#include "ParkingManager.h"

#include "models/Car.h"
#include "models/Motorcycle.h"
#include "models/Truck.h"

using namespace std;

int main() {

    ParkingLot parkingLot("City Parking");

    parkingLot.addFloor(1);
    parkingLot.addFloor(2);

    // 3. Add parking spots

    // Floor 1
    parkingLot.addParkingSpot(1, 101, VehicleType::MOTORCYCLE);
    parkingLot.addParkingSpot(1, 102, VehicleType::CAR);
    parkingLot.addParkingSpot(1, 103, VehicleType::CAR);

    // Floor 2
    parkingLot.addParkingSpot(2, 201, VehicleType::TRUCK);
    parkingLot.addParkingSpot(2, 202, VehicleType::CAR);
    parkingLot.addParkingSpot(2, 203, VehicleType::MOTORCYCLE);

    // 4. Create Parking Manager
    ParkingManager manager(parkingLot);

    // 5. Create vehicles
    shared_ptr<Vehicle> car =
        make_shared<Car>("RJ14AB1234");

    shared_ptr<Vehicle> bike =
        make_shared<Motorcycle>("RJ14CD5678");

    shared_ptr<Vehicle> truck =
        make_shared<Truck>("RJ14EF9012");

    // 6. Park vehicles
    cout << "\n========== PARKING VEHICLES ==========\n";

    manager.parkVehicle(car);
    manager.parkVehicle(bike);
    manager.parkVehicle(truck);

    // 7. Display active tickets
    cout << "\n========== ACTIVE TICKETS ==========\n";

    manager.displayActiveTickets();

    // 8. Unpark vehicles
    cout << "\n========== UNPARK VEHICLES ==========\n";

    manager.unparkVehicle("T1");
    manager.unparkVehicle("T2");

    // 9. Display remaining active tickets
    cout << "\n========== REMAINING ACTIVE TICKETS ==========\n";

    manager.displayActiveTickets();

    return 0;
}
