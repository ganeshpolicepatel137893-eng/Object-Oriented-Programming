#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- VEHICLE CLASS ----------------
class Vehicle {
public:
    int id;
    string type;
    double pricePerDay;
    bool available;

    Vehicle(int i, string t, double p) {
        id = i;
        type = t;
        pricePerDay = p;
        available = true;
    }

    void display() {
        cout << id << " - " << type 
             << " - ?" << pricePerDay 
             << " - " << (available ? "Available" : "Not Available") << endl;
    }
};

// ---------------- CUSTOMER CLASS ----------------
class Booking {
public:
    string customerId;
    string customerName;
    int vehicleId;
    int days;
    double totalBill;

    Booking(string cid, string cname, int vid, int d, double bill) {
        customerId = cid;
        customerName = cname;
        vehicleId = vid;
        days = d;
        totalBill = bill;
    }

    void display() {
        cout << "Customer ID: " << customerId << endl;
        cout << "Name: " << customerName << endl;
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Days: " << days << endl;
        cout << "Total Bill: ?" << totalBill << endl;
        cout << "----------------------\n";
    }
};

// ---------------- MAIN SYSTEM ----------------
class RentalSystem {
private:
    vector<Vehicle> vehicles;
    vector<Booking> bookings;

public:
    RentalSystem() {
        vehicles.push_back(Vehicle(1, "Car", 1000));
        vehicles.push_back(Vehicle(2, "Bike", 500));
        vehicles.push_back(Vehicle(3, "Truck", 2000));
    }

    // SHOW VEHICLES
    void showVehicles() {
        cout << "\n--- VEHICLES ---\n";
        for (auto &v : vehicles) {
            v.display();
        }
    }

    // BOOK VEHICLE
    void bookVehicle() {
        string cid, cname;
        int vid, days;

        cout << "Enter Customer ID: ";
        cin >> cid;

        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, cname);

        cout << "Enter Vehicle ID: ";
        cin >> vid;

        cout << "Enter Days: ";
        cin >> days;

        // VALIDATION
        if (vid < 1 || vid > vehicles.size()) {
            cout << "Invalid Vehicle ID!\n";
            return;
        }

        Vehicle &v = vehicles[vid - 1];

        if (!v.available) {
            cout << "Vehicle not available!\n";
            return;
        }

        double bill = v.pricePerDay * days;

        bookings.push_back(Booking(cid, cname, vid, days, bill));
        v.available = false;

        cout << "? Booking Successful!\n";
        cout << "Total Bill: ?" << bill << endl;
    }

    // COMPLETE BOOKING
    void completeBooking() {
        int vid;
        cout << "Enter Vehicle ID to complete: ";
        cin >> vid;

        if (vid < 1 || vid > vehicles.size()) {
            cout << "Invalid Vehicle ID!\n";
            return;
        }

        vehicles[vid - 1].available = true;
        cout << "? Booking Completed. Vehicle Returned.\n";
    }

    // CANCEL BOOKING
    void cancelBooking() {
        int vid;
        cout << "Enter Vehicle ID to cancel: ";
        cin >> vid;

        if (vid < 1 || vid > vehicles.size()) {
            cout << "Invalid Vehicle ID!\n";
            return;
        }

        vehicles[vid - 1].available = true;
        cout << "? Booking Cancelled.\n";
    }

    // SHOW BOOKINGS
    void showBookings() {
        if (bookings.empty()) {
            cout << "No bookings found.\n";
            return;
        }

        cout << "\n--- BOOKINGS ---\n";
        for (auto &b : bookings) {
            b.display();
        }
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    RentalSystem system;
    int choice;

    do {
        cout << "\n1. Show Vehicles\n";
        cout << "2. Book Vehicle\n";
        cout << "3. Complete Booking\n";
        cout << "4. Cancel Booking\n";
        cout << "5. Show Bookings\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.showVehicles(); break;
            case 2: system.bookVehicle(); break;
            case 3: system.completeBooking(); break;
            case 4: system.cancelBooking(); break;
            case 5: system.showBookings(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
