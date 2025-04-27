#include "ReservationSystem.h"

int main() {
    ReservationSystem system;
    system.addFlight(new DynamicFlight("AA101", "Hyderabad", "Delhi", 100, 150.0));
    system.addFlight(new DynamicFlight("BB202", "Chennai", "Pune", 80, 200.0));
    system.addFlight(new DynamicFlight("CC303", "Chicago", "Miami", 120, 180.0));

    int choice;
    string flightNumber;
    do {
        cout << "\n=== Flight Reservation System ===\n";
        cout << "1. Show Available Flights\n";
        cout << "2. Book a Flight\n";
        cout << "3. Cancel a Reservation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nAvailable Flights:\n";
                system.showAvailableFlights();
                break;
            case 2:
                cout << "Enter Flight Number to Book: ";
                cin >> flightNumber;
                system.bookFlight(flightNumber);
                break;
            case 3:
                cout << "Enter Flight Number to Cancel: ";
                cin >> flightNumber;
                system.cancelFlight(flightNumber);
                break;
            case 4:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    for (int i = 0; i < system.flightCount; ++i) {
        delete system.flights[i];
    }
    return 0;
}