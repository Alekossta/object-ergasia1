#include "Person.h"
#include "Secretary.h"
#include <iostream>
using namespace std;

int Person::count = 0;

int main() {
    // Creation and management of objects
    Secretary secretary;
    Person p1("John", 30), p2("Mary", 25), p3("Mark", 40);

    // Adding persons to the secretary
    secretary = secretary + p1;
    secretary = secretary + p2;
    secretary = secretary + p3;

    // Display total number of Person instances
    cout << "Total Persons: " << Person::getCount() << endl;

    // Display information about the persons managed by the secretary
    cout << secretary << endl;

    //Testing input and output operators for Person
    // input
    Person p4;
    secretary = secretary + p4;
    cin >> p4;

    // output
    cout << "*new*" << p4 << endl;

    // Find a person
    int idToFind = 2; // should be found
    if (secretary.findPerson(idToFind)) {
        cout << idToFind << " is managed by the secretary." << endl;
    } else {
        cout << idToFind << " is not managed by the secretary." << endl;
    }

    idToFind = 14; // should not be found
    if (secretary.findPerson(idToFind)) {
        cout << "id " << idToFind << " is managed the secretary." << endl;
    } else {
        cout << "id " << idToFind << " is not managed by the secretary." << endl;
    }
    
    cout << endl;

    // Testing input and output operators for Secretary
    // input
    cin >> secretary; // should add a person to secretary2

    // output
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
