#ifndef RESERVATION_SYSTEM_H
#define RESERVATION_SYSTEM_H

#include "Flight.h"

class ReservationSystem {
public:
    static const int MAX_FLIGHTS = 10;
    DynamicFlight* flights[MAX_FLIGHTS];
    int flightCount;

    ReservationSystem();
    void addFlight(DynamicFlight* flight);
    void showAvailableFlights();
    void bookFlight(const string& flightNumber);
    void cancelFlight(const string& flightNumber);
};

#endif