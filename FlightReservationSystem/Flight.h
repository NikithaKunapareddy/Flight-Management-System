#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
using namespace std;

class Flight {
protected:
    string flightNumber;
    string origin;
    string destination;
    int totalSeats;
    int bookedSeats;
    double basePrice;
public:
    Flight(string fn, string orig, string dest, int seats, double price);
    virtual double calculatePrice() = 0;
    bool bookSeat();
    bool cancelSeat();
    void showFlightInfo();
    int getAvailableSeats() const;
    string getFlightNumber() const;
};

class DynamicFlight : public Flight {
public:
    DynamicFlight(string fn, string orig, string dest, int seats, double price);
    double calculatePrice() override;
};

#endif