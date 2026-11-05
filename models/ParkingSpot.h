#pragma once

#include "Vehicle.h"

class ParkingSpot {
private:
    int spotId;
    VehicleType spotType;
    Vehicle* vehicle = nullptr;

public:
    ParkingSpot(int id, VehicleType type)
        : spotId(id), spotType(type) {}

    bool isAvailable() const {
        return vehicle == nullptr;
    }

    bool canFitVehicle(const Vehicle& v) const {
        return isAvailable() &&
               spotType == v.getVehicleType();
    }

    bool parkVehicle(Vehicle* v) {
        if (v == nullptr || !canFitVehicle(*v)) {
            return false;
        }

        vehicle = v;
        return true;
    }

    void removeVehicle() {
        vehicle = nullptr;
    }

    int getSpotId() const {
        return spotId;
    }

    VehicleType getSpotType() const {
        return spotType;
    }
};