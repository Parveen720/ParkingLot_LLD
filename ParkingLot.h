#pragma once

#include <string>
#include <vector>
#include <utility>
#include <iostream>

#include "models/ParkingFloor.h"

using namespace std;

class ParkingLot {
private:
    string name;
    vector<ParkingFloor> floors;

public:
    ParkingLot(string lotName) {
        name = lotName;
    }

    void addFloor(int floorId) {
        floors.emplace_back(floorId);
    }

    void addParkingSpot(
        int floorId,
        int spotId,
        VehicleType type
    ) {
        for (auto& floor : floors) {
            if (floor.getFloorId() == floorId) {
                floor.addParkingSpot(spotId, type);
                return;
            }
        }

        cout << "Floor not found!\n";
    }

    pair<ParkingSpot*, int> findAvailableSpot(
        VehicleType type
    ) {
        for (auto& floor : floors) {
            ParkingSpot* spot =
                floor.findAvailableSpot(type);

            if (spot != nullptr) {
                return {spot, floor.getFloorId()};
            }
        }

        return {nullptr, -1};
    }

    ParkingSpot* getSpot(int floorId, int spotId) {
        for (auto& floor : floors) {
            if (floor.getFloorId() == floorId) {
                return floor.getSpot(spotId);
            }
        }

        return nullptr;
    }

    string getName() const {
        return name;
    }
};