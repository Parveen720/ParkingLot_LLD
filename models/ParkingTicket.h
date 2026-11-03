
#pragma once
#include <string>
#include <chrono>
#include "../enums/VehicleType.h"

using namespace std;

class ParkingTicket {

private:
    string ticketId;
    string vehicleNumber;

    VehicleType vehicleType;

    int floorId;
    int spotId;

    chrono::system_clock::time_point entryTime;
    chrono::system_clock::time_point exitTime;

    bool active;

public:

    ParkingTicket(string id, string number,
                  VehicleType type, int floor, int spot)
        : ticketId(id),
          vehicleNumber(number),
          vehicleType(type),
          floorId(floor),
          spotId(spot),
          entryTime(chrono::system_clock::now()),
          active(true) {
    }

    void close() {
        if (active) {
            exitTime = chrono::system_clock::now();
            active = false;
        }
    }

    double getBillableHours() const {

        if (active) {
            return 0;
        }

        auto duration = chrono::duration_cast<
            chrono::seconds>(exitTime - entryTime);

        long long seconds = duration.count();

        // Round up partial hours.
        int hours = (seconds + 3599) / 3600;

        // Minimum one hour charge.
        return max(1, hours);
    }

    string getTicketId() const {
        return ticketId;
    }

    string getVehicleNumber() const {
        return vehicleNumber;
    }

    VehicleType getVehicleType() const {
        return vehicleType;
    }

    int getFloorId() const {
        return floorId;
    }

    int getSpotId() const {
        return spotId;
    }

    bool isActive() const {
        return active;
    }
};
