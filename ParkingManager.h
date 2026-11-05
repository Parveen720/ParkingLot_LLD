#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

#include "ParkingLot.h"
#include "models/ParkingTicket.h"
#include "models/Vehicle.h"

using namespace std;

class ParkingManager {
private:
    ParkingLot& parkingLot;

    unordered_map<string, ParkingTicket> activeTickets;

    int nextTicketId = 1;

    double getHourlyRate(VehicleType type) const {
        switch (type) {
            case VehicleType::MOTORCYCLE:
                return 20.0;

            case VehicleType::CAR:
                return 50.0;

            case VehicleType::TRUCK:
                return 100.0;
        }

        return 0.0;
    }

public:
    ParkingManager(ParkingLot& lot)
        : parkingLot(lot) {}

    // Park vehicle
    bool parkVehicle(Vehicle* vehicle) {

        if (vehicle == nullptr) {
            cout << "Invalid vehicle!\n";
            return false;
        }

        auto [spot, floorId] =
            parkingLot.findAvailableSpot(
                vehicle->getVehicleType()
            );

        if (spot == nullptr) {
            cout << "No parking spot available!\n";
            return false;
        }

        if (!spot->parkVehicle(vehicle)) {
            return false;
        }

        string ticketId =
            "T" + to_string(nextTicketId++);

        ParkingTicket ticket(
            ticketId,
            vehicle->getVehicleNumber(),
            vehicle->getVehicleType(),
            floorId,
            spot->getSpotId()
        );

        activeTickets.emplace(ticketId, ticket);

        cout << "\nVehicle parked successfully!\n";
        cout << "Ticket ID: " << ticketId << "\n";
        cout << "Floor ID: " << floorId << "\n";
        cout << "Spot ID: " << spot->getSpotId() << "\n";

        return true;
    }

    // Unpark vehicle
    bool unparkVehicle(const string& ticketId) {

        auto it = activeTickets.find(ticketId);

        if (it == activeTickets.end()) {
            cout << "Invalid ticket ID!\n";
            return false;
        }

        ParkingTicket& ticket = it->second;

        if (!ticket.isActive()) {
            cout << "Ticket is already closed!\n";
            return false;
        }

        ParkingSpot* spot = parkingLot.getSpot(
            ticket.getFloorId(),
            ticket.getSpotId()
        );

        if (spot == nullptr) {
            cout << "Parking spot not found!\n";
            return false;
        }

        ticket.close();

        double hours = ticket.getBillableHours();

        double rate =
            getHourlyRate(ticket.getVehicleType());

        double amount = hours * rate;

        spot->removeVehicle();

        cout << "\nVehicle unparked successfully!\n";
        cout << "Vehicle Number: "
             << ticket.getVehicleNumber() << "\n";

        cout << "Parking Hours: " << hours << "\n";
        cout << "Hourly Rate: Rs. " << rate << "\n";
        cout << "Total Amount: Rs. " << amount << "\n";

        return true;
    }

    // Display active tickets
    void displayActiveTickets() const {

        if (activeTickets.empty()) {
            cout << "No active parking tickets!\n";
            return;
        }

        cout << "\nActive Parking Tickets:\n";

        for (const auto& entry : activeTickets) {

            const ParkingTicket& ticket = entry.second;

            if (ticket.isActive()) {

                cout << "Ticket ID: "
                     << ticket.getTicketId() << "\n";

                cout << "Vehicle Number: "
                     << ticket.getVehicleNumber() << "\n";

                cout << "Floor ID: "
                     << ticket.getFloorId() << "\n";

                cout << "Spot ID: "
                     << ticket.getSpotId() << "\n";

                cout << "----------------------\n";
            }
        }
    }
};