#include "Person.h"
#include "Secretary.h"
#include <iostream>
using namespace std;

int Person::count = 0;

int main() {
    // Creation and management of objects
    Secretary secretary;
    Person p1(25, "John"), p2(30, "Jane");

    // Adding persons to the secretary
    secretary = secretary + p1;
    secretary = secretary + p2;

    // Display total number of Person instances
    cout << "Total Persons: " << Person::getCount() << endl;

    // Display information about the persons managed by the secretary
    cout << "Persons managed by the secretary:" << endl;
    cout << secretary << endl;

    
    // Find a person
    string nameToFind = "John"; // should be found
    if (secretary.findPerson(nameToFind)) {
        cout << nameToFind << " is managed by the secretary." << endl;
    } else {
        cout << nameToFind << " is not managed by the secretary." << endl;
    }

    string nameToFind2 = "George"; // should not be found
    if (secretary.findPerson(nameToFind2)) {
        cout << nameToFind2 << " is managed by the secretary." << endl;
    } else {
        cout << nameToFind2 << " is not managed by the secretary." << endl;
    }

    return 0;
}
