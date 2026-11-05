#pragma once

#include <vector>
#include "ParkingSpot.h"

using namespace std;

class ParkingFloor {
private:
    int floorId;
    vector<ParkingSpot> spots;

public:
    ParkingFloor(int id) : floorId(id) {}

    void addParkingSpot(int spotId, VehicleType type) {
        spots.emplace_back(spotId, type);
    }

    ParkingSpot* findAvailableSpot(VehicleType type) {
        for (auto& spot : spots) {
            if (spot.isAvailable() &&
                spot.getSpotType() == type) {
                return &spot;
            }
        }

        return nullptr;
    }

    ParkingSpot* getSpot(int spotId) {
        for (auto& spot : spots) {
            if (spot.getSpotId() == spotId) {
                return &spot;
            }
        }

        return nullptr;
    }

    int getFloorId() const {
        return floorId;
    }
};