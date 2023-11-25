#include "Person.h"
#include "Secretary.h"
#include <iostream>

using namespace std;

int Person::count = 0;

int main() {

    Secretary secretary;

    Person p1("John", 18), p2("Mary", 19), p3("Mark", 20);

    secretary += p1;
    secretary += p2;
    secretary += p3;

    cout << "Total Persons: " << Person::getCount() << endl;

    cout << secretary << endl;

    // testing input operator for person and then adding to secretary
    Person p4;
    cin >> p4;
    secretary += p4;

    // Find a person
    
    int idToFind = 2; // should be found
    cout << "Searching for " << idToFind << "..." << endl;
    if (secretary.findPerson(idToFind)) {
        cout << idToFind << " was found in the secretary." << endl;
    } else {
        cout << idToFind << " was not found in the secretary." << endl;
    }

    idToFind = 14; // should not be found
    cout << "Searching for " << idToFind << "..." << endl;
    if (secretary.findPerson(idToFind)) {
        cout << idToFind << " was found in the secretary." << endl;
    } else {
        cout << idToFind << " was not found in the secretary." << endl;
    }
    
    cout << endl;

    // Testing input and output operators for Secretary
    cin >> secretary;
    cout << secretary << endl;

    // getCount() should return 4
    cout << "Total Persons: " << Person::getCount() << endl;

    cout << endl;

    // Testing copy constructor
    cout << "Testing copy constructor" << endl;
    Secretary secretary2 = secretary;
    cout << secretary2 << endl;
    cout << "Total Persons: " << Person::getCount() << endl;

    return 0;
}
