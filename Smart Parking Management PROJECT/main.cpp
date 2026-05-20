#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;
// VEHICLE BASE CLASS
class Vehicle {
protected:
    string plateNumber;
    string ownerName;
    string vehicleType;
public:
     Vehicle() {
        plateNumber = "";
        ownerName = "";
        vehicleType = "";
    }
    Vehicle(string plate, string owner, string type) {
        plateNumber = plate;
        ownerName = owner;
        vehicleType = type;
    }
    string getPlateNumber() {
        return plateNumber;
    }

    string getOwnerName() {
        return ownerName;
    }
    string getVehicleType() {
        return vehicleType;
    }
    virtual double calculateFee(int hours) {
         if(hours <= 1)
            return 100;
            return 100 + (hours - 1) * 50;
    }
    virtual void displayVehicle() {
           cout << left << setw(15) << plateNumber
             << setw(20) << ownerName
             << setw(15) << vehicleType;
    }
    virtual ~Vehicle() {}
};
// CAR CLASS
class Car : public Vehicle {
public:
   Car(string plate, string owner):Vehicle(plate, owner, "Car"){}
     double calculateFee(int hours) override {
            if(hours <= 1)
            return 150;
         return 150 + (hours - 1) * 70;
    }
};
//  MOTORCYCLE CLASS
class Motorcycle : public Vehicle {
public:
    Motorcycle(string plate, string owner)
        : Vehicle(plate, owner, "Motorcycle") {}
    double calculateFee(int hours) override {
            if(hours <= 1)
            return 50;
            return 50 + (hours - 1) * 30;
    }
};
// TRUCK CLASS
class Truck : public Vehicle {
public:
    Truck(string plate, string owner)
        : Vehicle(plate, owner, "Truck") {}
    double calculateFee(int hours) override {
            if(hours <= 1)
            return 300;
            return 300 + (hours - 1) * 120;
    }
};
// TICKET CLASS
class Ticket {
private:
    int ticketID;
    int slotNumber;
    int hoursParked;
    double parkingFee;
public:
    Ticket() {
        ticketID = 0;
        slotNumber = 0;
        hoursParked = 0;
        parkingFee = 0;
    }
Ticket(int id, int slot, int hours, Vehicle* v) {

        ticketID = id;
        slotNumber = slot;
        hoursParked = hours;
        parkingFee = v->calculateFee(hours);
    }
void displayTicket() {

        cout << "\n====================================\n";
        cout << "          PARKING TICKET\n";
        cout << "====================================\n";
        cout << "Ticket ID     : " << ticketID << endl;
        cout << "Slot Number   : " << slotNumber << endl;
        cout << "Hours Parked  : " << hoursParked << endl;
        cout << "Parking Fee   : KES " << parkingFee << endl;
        cout << "====================================\n";
    }
};
class ParkingSlot {
private:
    int slotNumber;
    bool occupied;
    Vehicle* vehicle;
    time_t entryTime;

public:
ParkingSlot() {
        slotNumber = 0;
        occupied = false;
        vehicle = nullptr;
        entryTime = 0;
    }
ParkingSlot(int number) {
        slotNumber = number;
        occupied = false;
        vehicle = nullptr;
        entryTime = 0;
    }

    bool isOccupied() {
        return occupied;
    }

    int getSlotNumber() {
        return slotNumber;
    }

    Vehicle* getVehicle() {
        return vehicle;
    }

    time_t getEntryTime() {
        return entryTime;
    }

    void parkVehicle(Vehicle* v) {

        vehicle = v;
        occupied = true;

        // RECORD CURRENT TIME
        entryTime = time(0);
    }

    void removeVehicle() {

        delete vehicle;

        vehicle = nullptr;
        occupied = false;
        entryTime = 0;
    }

    void displaySlot() {

        cout << "\nSlot " << slotNumber << " : ";

        if(occupied) {

            cout << "Occupied\n";

            cout << left << setw(15) << "Plate No"
                 << setw(20) << "Owner"
                 << setw(15) << "Type" << endl;

            vehicle->displayVehicle();
            cout << endl;
        }

        else {
            cout << "Empty\n";
        }
    }
};
class ParkingSystem {

private:

    vector<ParkingSlot> slots;

    int totalSlots;
    int nextTicketID;

public:

    ParkingSystem(int numberOfSlots) {

        totalSlots = numberOfSlots;

        nextTicketID = 100;

        for(int i = 1; i <= totalSlots; i++) {

            slots.push_back(ParkingSlot(i));
        }
    }
    void parkVehicle() {

        string plate, owner;

        int type;

        cout << "\nEnter Plate Number: ";
        cin >> plate;

        cin.ignore();

        cout << "Enter Owner Name: ";
        getline(cin, owner);

        cout << "\nSelect Vehicle Type:\n";
        cout << "1. Car\n";
        cout << "2. Motorcycle\n";
        cout << "3. Truck\n";
        cout << "Choice: ";
        cin >> type;

        Vehicle* v;

        if(type == 1) {

            v = new Car(plate, owner);
        }

        else if(type == 2) {

            v = new Motorcycle(plate, owner);
        }

        else {

            v = new Truck(plate, owner);
        }

        for(int i = 0; i < totalSlots; i++) {

            if(!slots[i].isOccupied()) {

                slots[i].parkVehicle(v);

                cout << "\nVehicle Parked Successfully!\n";

                cout << "Allocated Slot: "
                     << slots[i].getSlotNumber() << endl;

                cout << "Entry Time Recorded Automatically.\n";

                return;
            }
        }

        cout << "\nParking Full!\n";
    }
    void removeVehicle() {

        string plate;

        cout << "\nEnter Plate Number: ";
        cin >> plate;

        bool found = false;

        for(int i = 0; i < totalSlots; i++) {

            if(slots[i].isOccupied() &&
               slots[i].getVehicle()->getPlateNumber() == plate) {

                // CURRENT EXIT TIME
                time_t exitTime = time(0);

                // ENTRY TIME
                time_t entryTime = slots[i].getEntryTime();

                // CALCULATING HOURS
                double seconds = difftime(exitTime, entryTime);

                int hours = seconds / 3600;

                // MINIMUM 1 HOUR
                if(hours < 1) {
                    hours = 1;
                }

                Ticket ticket(
                    nextTicketID,
                    slots[i].getSlotNumber(),
                    hours,
                    slots[i].getVehicle()
                );

                nextTicketID++;

                ticket.displayTicket();

                cout << "\nPayment Received Successfully.\n";
                cout << "Vehicle Removed.\n";

                slots[i].removeVehicle();

                found = true;

                break;
            }
        }

        if(!found) {

            cout << "\nVehicle Not Found!\n";
        }
    }
    void searchVehicle() {

        string plate;

        cout << "\nEnter Plate Number: ";
        cin >> plate;

        bool found = false;

        for(int i = 0; i < totalSlots; i++) {

            if(slots[i].isOccupied() &&
               slots[i].getVehicle()->getPlateNumber() == plate) {

                cout << "\nVehicle Found!\n";

                cout << "Slot Number: "
                     << slots[i].getSlotNumber() << endl;

                cout << left << setw(15) << "Plate No"
                     << setw(20) << "Owner"
                     << setw(15) << "Type" << endl;

                slots[i].getVehicle()->displayVehicle();

                cout << endl;

                found = true;

                break;
            }
        }

        if(!found) {

            cout << "\nVehicle Not Found!\n";
        }
    }
    void displayParkingStatus() {

        cout << "\n============= PARKING STATUS =============\n";

        for(int i = 0; i < totalSlots; i++) {

            slots[i].displaySlot();
        }
    }
    void availableSlots() {

        int count = 0;

        for(int i = 0; i < totalSlots; i++) {

            if(!slots[i].isOccupied()) {

                count++;
            }
        }

        cout << "\nAvailable Slots: "
             << count << endl;
    }
};

// MAIN FUNCTION
int main() {

    ParkingSystem parking(20);

    int choice;

    do {

        cout << "\n=====================================\n";
        cout << "      PARKING MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Park Vehicle\n";
        cout << "2. Remove Vehicle / Payment\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Display Parking Status\n";
        cout << "5. Show Available Slots\n";
        cout << "6. Exit\n";

        cout << "=====================================\n";

        cout << "Enter Choice: ";

        cin >> choice;

        switch(choice) {

        case 1:
            parking.parkVehicle();
            break;

        case 2:
            parking.removeVehicle();
            break;

        case 3:
            parking.searchVehicle();
            break;

        case 4:
            parking.displayParkingStatus();
            break;

        case 5:
            parking.availableSlots();
            break;

        case 6:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}
