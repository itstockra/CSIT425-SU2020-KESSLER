// Author: Matthew Kessler
// CarRental Class

#include <iostream>
#include <iomanip>
using namespace std;

// CarRental class stores information about rental cars
// Acts as node for linked list
class CarRental {
    private:
        int quantity;
        int year;
        string brand;
        string model;
        string type;
        int capacity;
        CarRental *next;
    public:
        CarRental() {};
        ~CarRental();
        CarRental(int q, int y, string b, string m, string t, int c) : 
        quantity(q), year(y), brand(b), model(m), type(t), capacity(c), next(nullptr) {};
        
        CarRental* getNext() { return next; }
        
        void setNext(CarRental *n) { next = n; }

        int getCapacity() { return capacity; }
        
        // printInfo function
        // prints formatted information for single car in list
        void printInfo() {
            cout << left << setw(7)<< quantity << setw(6) << year << setw(10) << brand << setw(12) << model 
            << setw(7) << type << setw(10) << capacity << endl;
        }
    };