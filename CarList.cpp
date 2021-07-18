// Author: Matthew Kessler
// CarList Class

#include <iostream>
#include <iomanip>
#include "CarRental.cpp"
using namespace std;

//CarList class => controls the list made from CarRental class
class CarList {
    
    private:
        int carCount;
        CarRental *rootPtr, *tailPtr, *iterPtr;
    
    public:
        CarList() : rootPtr(nullptr), tailPtr(nullptr), carCount(0) {};
        ~CarList();
        
        // isEmpty function
        // returns True if list is empty, false otherwise
        bool isEmpty() const;

        // addCar function
        // Adds a new car entry to the tail of the current list of cars.
        void addCar(const int& q, const int&y, const string& b, const string& m, const string& t, const int& c);

        // printAll function
        // Prints the entire list of cars.
        void printAll();

        // getCarsWithCapacity function
        // Prints all cars in list that have matching capacity specified by user.
        // Parameter: cap => int, value to test against list of car capacities.
        void getCarsWithCapacity(const int& cap);

         
    
};

bool CarList::isEmpty() const {
    return carCount == 0;
}

void CarList::addCar(const int& q, const int&y, const string& b, const string& m, const string& t, const int& c) {
    CarRental *newCar = new CarRental(q, y, b, m, t, c);
    if (isEmpty()) {
        rootPtr = newCar;
        tailPtr = newCar;
    }
    else {
        iterPtr = tailPtr;
        tailPtr->setNext(newCar);
        tailPtr = newCar;
    }
    carCount++;
}

void CarList::printAll() {
    iterPtr = rootPtr;
    int i = 1;
    cout<< left << setw(4) << "#" << setw(7) <<"Quant." << setw(6) <<"Year" 
    << setw(10) <<"Brand" << setw(12) <<"Model" << setw(7) <<"Type" << setw(10) << "Capacity" << endl;
    while (iterPtr != nullptr) {
        cout << setw(4) << i;
        iterPtr->printInfo();
        iterPtr = iterPtr->getNext();
        i++;
    }
}

void CarList::getCarsWithCapacity(const int& cap) {
    iterPtr = rootPtr;

    cout << left << setw(4) << "#" << setw(7) <<"Quant." << setw(6) <<"Year" 
    << setw(10) <<"Brand" << setw(12) <<"Model" << setw(7) <<"Type" << setw(10) << "Capacity" << endl;

    bool isMatch = false;
    int i = 1;
    while (iterPtr != nullptr) {
        if (iterPtr->getCapacity() == cap) {
            cout << left << setw(4) << i;
            iterPtr->printInfo();
            i++;
            isMatch = true;
        }
        iterPtr = iterPtr->getNext();
    }
    if (!isMatch) {
        cout << "Sorry, no cars with a capacity of " << cap << "." << endl;
    }
}