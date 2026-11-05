#pragma once

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(string number) : Vehicle(number) {}

    VehicleType getVehicleType() const override {
        return VehicleType::CAR;
    }
};