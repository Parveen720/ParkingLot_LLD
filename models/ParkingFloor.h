#pragma once

#include <vector>
#include <memory>
#include "ParkingSpot.h"

class ParkingFloor {

private:
    int floorId;

    vector<unique_ptr<ParkingSpot>> spots;

public:

    ParkingFloor(int id) : floorId(id) {
    }

    void addParkingSpot(int spotId, VehicleType type) {

        spots.push_back(
            make_unique<ParkingSpot>(spotId, type)
        );
    }

    ParkingSpot* findAvailableSpot(VehicleType type) {

        for (auto& spot : spots) {

            if (spot->isAvailable() &&
                spot->getSpotType() == type) {

                return spot.get();
            }
        }

        return nullptr;
    }

    ParkingSpot* getSpot(int spotId) {

        for (auto& spot : spots) {

            if (spot->getSpotId() == spotId) {
                return spot.get();
            }
        }

        return nullptr;
    }

    int getFloorId() const {
        return floorId;
    }
};
