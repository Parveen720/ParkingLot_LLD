#pragma once

#include "Vehicle.h"

class Motorcycle : public Vehicle {

public:

    Motorcycle(string number) : Vehicle(number) {

    }

    VehicleType getVehicleType() const override {
        return VehicleType::MOTORCYCLE;
    }
};
