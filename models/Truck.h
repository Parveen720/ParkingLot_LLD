#pragma once

#include "Vehicle.h"

class Truck : public Vehicle {

public:

    Truck(string number) : Vehicle(number) {

    }

    VehicleType getVehicleType() const override {
        return VehicleType::TRUCK;
    }
};
