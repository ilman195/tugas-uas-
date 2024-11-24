//kelompol 3 anggrek mekar //
//nama kelompok//
// ilman arifin A.R 2410631170143 //
// haikal quds 2410631170141 //
//  Aditya Anugrah Pangestu 2410631170052 //

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Guest {
public:
    string name;
    int roomNumber;

    Guest(string name, int roomNumber) : name(name), roomNumber(roomNumber) {}
};

class HotelReception {
private:
    vector<Guest> guests;

public:
    void checkIn(string name, int roomNumber) {
        guests.push_back(Guest(name, roomNumber));
        cout << "Check-in successful for " << name << " in room " << roomNumber << "." << endl;
    }

    void checkOut(int roomNumber) {
        for (auto it = guests.begin(); it != guests.end(); ++it) {
            if (it->roomNumber == roomNumber) {
                cout << "Check-out successful for " << it->name << " from room " << roomNumber << "." << endl;
                guests.erase(it);
                return;
            }
        }
        cout << "Room " << roomNumber << " not found!" << endl;
    }

    void listGuests() {
        if (guests.empty()) {
            cout << "No guests currently checked in." << endl;
            return;
        }
        cout << "Current guests:" << endl;
        for (const auto& guest : guests) {
            cout << "Name: " << guest.name << ", Room Number: " << guest.roomNumber << endl;
        }
    }
};

int main() {
    HotelReception reception;
    int choice;

    do {
        cout << "\nHotel Reception Menu:" << endl;
        cout << "1. Check-in" << endl;
        cout << "2. Check-out" << endl;
        cout << "3. List Guests" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int roomNumber;
                cout << "Enter guest name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter room number: ";
                cin >> roomNumber;
                reception.checkIn(name, roomNumber);
                break;
            }
            case 2: {
                int roomNumber;
                cout << "Enter room number for check-out: ";
                cin >> roomNumber;
                reception.checkOut(roomNumber);
                break;
            }
            case 3:
                reception.listGuests();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
