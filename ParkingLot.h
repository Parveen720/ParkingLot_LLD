#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>

#include "models/ParkingFloor.h"

using namespace std;

class ParkingLot {

private:
    string name;

    vector<unique_ptr<ParkingFloor>> floors;

public:

    ParkingLot(string lotName) {
        name = lotName;
    }

    void addFloor(int floorId) {

        floors.push_back(
            make_unique<ParkingFloor>(floorId)
        );
    }

    // Add parking spot to a particular floor
    void addParkingSpot(int floorId, int spotId,
                        VehicleType type) {

        for (auto& floor : floors) {

            if (floor->getFloorId() == floorId) {

                floor->addParkingSpot(spotId, type);
                return;
            }
        }

        cout << "Floor not found!\n";
    }

  
    pair<ParkingSpot*, int> findAvailableSpot(
        VehicleType type) {

        for (auto& floor : floors) {

            ParkingSpot* spot =
                floor->findAvailableSpot(type);

            if (spot != nullptr) {

                return {spot, floor->getFloorId()};
            }
        }

        return {nullptr, -1};
    }

    // Find spot using floor ID and spot ID
    ParkingSpot* getSpot(int floorId, int spotId) {

        for (auto& floor : floors) {

            if (floor->getFloorId() == floorId) {

                return floor->getSpot(spotId);
            }
        }

        return nullptr;
    }

    // Get parking lot name
    string getName() const {
        return name;
    }
};
