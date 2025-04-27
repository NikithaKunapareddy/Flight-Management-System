#include "ReservationSystem.h"
#include <iostream>
using namespace std;

ReservationSystem::ReservationSystem() : flightCount(0) {}

void ReservationSystem::addFlight(DynamicFlight* flight) {
    if (flightCount < MAX_FLIGHTS) {
        flights[flightCount++] = flight;
    } else {
        cout << "Cannot add more flights, maximum limit reached." << endl;
    }
}

void ReservationSystem::showAvailableFlights() {
    if (flightCount == 0) {
        cout << "No flights available.\n";
        return;
    }
    for (int i = 0; i < flightCount; i++) {
        flights[i]->showFlightInfo();
        cout << "Current Price: $" << flights[i]->calculatePrice() << endl;
        cout << "-----------------------------------\n";
    }
}

void ReservationSystem::bookFlight(const string& flightNumber) {
    for (int i = 0; i < flightCount; i++) {
        if (flights[i]->getFlightNumber() == flightNumber) {
            if (flights[i]->bookSeat()) {
                cout << "Flight booked successfully!\n";
                cout << "Final Price: $" << flights[i]->calculatePrice() << endl;
            }
            return;
        }
    }
    cout << "Flight not found.\n";
}

void ReservationSystem::cancelFlight(const string& flightNumber) {
    for (int i = 0; i < flightCount; i++) {
        if (flights[i]->getFlightNumber() == flightNumber) {
            if (flights[i]->cancelSeat()) {
                cout << "Reservation canceled successfully!\n";
            }
            return;
        }
    }
    cout << "Flight not found.\n";
}