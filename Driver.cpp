// Author: Matthew Kessler
// Driver.cpp 
// Driver to test CarRental and CarList classes

#include <iostream>
#include "CarList.cpp"
using namespace std;

// function checkInput
// validates that user entry contains only digits
// returns True if valid, false otherwise
bool checkInput(string);    

int main()
{
    // Construct car list object and populate list.
    CarList *aList = new CarList();
    aList->addCar(5, 1975, "Ford", "F-150", "Truck", 3);
    aList->addCar(2, 2004, "GMC", "Yukon", "SUV", 8);
    aList->addCar(1, 2002, "Toyota", "Carolla", "Sedan", 5);
    aList->addCar(3, 2012, "Honda", "Civic", "Sedan", 5);
    aList->addCar(4, 2021, "Tesla", "Model S", "Sedan", 5);
    aList->addCar(2, 2011, "Cadillac", "Escalade", "SUV", 8);
    aList->addCar(3, 2016, "Porsche", "911 Carrera", "Sedan", 4);
    aList->addCar(2, 2020, "Lexus", "GX", "SUV", 7);
    aList->addCar(2, 2017, "Kia", "Telluride", "SUV", 8);
    aList->addCar(1, 2019, "BMW", "3 Series", "Sedan", 5);
    
    // string 'selection' => controls menu from user input
    string selection = "0";
    
    // Begin menu loop
    menuStart:
    cout << "----------------------------------------------------------" << endl;
    cout << "------------ Welcome to Kessler Rental Cars --------------" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "-- Choose a menu option and hit [Enter] ------------------" << endl;
    cout << "(1) Display listing of all cars." << endl;
    cout << "(2) Find car by capacity." << endl;
    cout << "(3) Quit program." << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Enter Selection ==> ";
    cin >> selection;
    cout << endl;

    // Option 1 selected.
    // Display listing of all cars.
    if (selection[0] == '1') {
        cout << endl; aList->printAll(); cout << endl;
        goto menuStart;
    }
    // Option 2 selected.
    // Allow customer to search cars by capacity 
    else if (selection[0] == '2') {
        string custCapString;
        
        startOfSelection:
        cout << endl << "Please enter capacity desired ==> ";
        cin >> custCapString;
        cout << endl;
        if (checkInput(custCapString)) {
            // if string is valid, convert to integer
            int custCapInt = atoi(custCapString.c_str());   
            // Call function to return cars that match capacity entered
            aList->getCarsWithCapacity(custCapInt); cout << endl;

            char yesOrNo;

            searchAgain:
            cout << "Search again? (y/n) ==> ";
            cin >> yesOrNo;
            cout << endl;
            if (yesOrNo == 'y') {
                goto startOfSelection;
            }
            else if (yesOrNo == 'n') {
                goto menuStart;
            }
            else {
                cout << "Invalid entry." << endl;
                goto searchAgain;
            }
        }
        else {
            cout << "Invalid capacity, try again." << endl;
            goto startOfSelection;
        }
        

    }
    // Option 3 selected.
    // Quit the program by jumping to end of loop.
    else if (selection[0] == '3') {
        goto endOfLoop;
    }
    // Option 4
    // Any entry except 1, 2, or 3
    else {
        cout << "Invalid entry, please try again." << endl;
        goto menuStart;
    }

    endOfLoop:

    return 0;
}

// function checkInput definition
// returns True if string contains only digits
// returns False otherwise
bool checkInput(string s) {
    bool isValid = true;
    
    for (int i = 0; i < s.size(); i++) {
        if(!isdigit(s[i])) {
            isValid = false;
            i = s.size();        //exit loop as soon as a non-digit is recognized
        }
    }
    return isValid;
}