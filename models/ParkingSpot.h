#pragma once

#include <memory>
#include "Vehicle.h"
using namespace std;
class ParkingSpot {

private:
    int spotId;
    VehicleType spotType;
    shared_ptr<Vehicle> vehicle;

public:

    ParkingSpot(int id, VehicleType type)
        : spotId(id), spotType(type) {
    }

    bool isAvailable() const {
        return vehicle == nullptr;
    }

    bool canFitVehicle(const Vehicle& v) const {
        return isAvailable() &&
               spotType == v.getVehicleType();
    }

    bool parkVehicle(shared_ptr<Vehicle> v) {

        if (v == nullptr || !canFitVehicle(*v)) {
            return false;
        }

        vehicle = v;
        return true;
    }

    void removeVehicle() {
        vehicle.reset();
    }

    int getSpotId() const {
        return spotId;
    }

    VehicleType getSpotType() const {
        return spotType;
    }
};
