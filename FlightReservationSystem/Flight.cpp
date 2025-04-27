#include "Flight.h"

Flight::Flight(string fn, string orig, string dest, int seats, double price)
    : flightNumber(fn), origin(orig), destination(dest),
      totalSeats(seats), bookedSeats(0), basePrice(price) {}

bool Flight::bookSeat() {
    if (bookedSeats < totalSeats) {
        bookedSeats++;
        return true;
    } else {
        cout << "No seats available on flight " << flightNumber << endl;
        return false;
    }
}

bool Flight::cancelSeat() {
    if (bookedSeats > 0) {
        bookedSeats--;
        return true;
    } else {
        cout << "No seats are currently booked on flight " << flightNumber << endl;
        return false;
    }
}

void Flight::showFlightInfo() {
    cout << "Flight Number: " << flightNumber << "\nOrigin: " << origin
         << "\nDestination: " << destination << "\nAvailable Seats: "
         << (totalSeats - bookedSeats) << "\nBase Price: $" << basePrice << endl;
}

int Flight::getAvailableSeats() const {
    return totalSeats - bookedSeats;
}

string Flight::getFlightNumber() const {
    return flightNumber;
}

DynamicFlight::DynamicFlight(string fn, string orig, string dest, int seats, double price)
    : Flight(fn, orig, dest, seats, price) {}

double DynamicFlight::calculatePrice() {
    double demandFactor = (double)bookedSeats / totalSeats;
    return basePrice * (1 + demandFactor);
}