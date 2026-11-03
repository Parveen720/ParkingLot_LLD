#pragma once

#include <string>
#include "../enums/VehicleType.h"

using namespace std;

class Vehicle {
protected:
    string vehicleNumber;

public:
    Vehicle(string number) {
        vehicleNumber = number;
    }

    virtual VehicleType getVehicleType() const = 0;

    string getVehicleNumber() const {
        return vehicleNumber;
    }

    virtual ~Vehicle() = default;
};
