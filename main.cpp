#include "Person.h"
#include "Secretary.h"
#include <iostream>

using namespace std;

int Person::count = 0;

int main() {

    Secretary secretary("DIT");

    Person p1("John", 18), p2("Mary", 19), p3("Mark", 20);

    // testing output operator for person
    std::cout << "---Persons---" << std::endl;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    std::cout << "-------------";
    cout << " Total Persons: " << Person::getCount() << endl;

    // add everyone to the secretary
    secretary = secretary + p1;
    secretary += p2;
    secretary += p3;

    // print secretary
    cout << secretary << endl;

    // testing input operator for person and then adding to secretary
    Person p4;
    cin >> p4;
    secretary += p4;

    // Find a person
    std::cout << "---Begin Searching---" << std::endl;
    int idToFind = 2; // should be found
    cout << "Searching for id=" << idToFind << "..." << endl;
    if (secretary.findPerson(idToFind)) {
        cout << idToFind << " was found in the secretary." << endl;
    } else {
        cout << idToFind << " was not found in the secretary." << endl;
    }

    idToFind = 14; // should not be found
    cout << "Searching for id=" << idToFind << "..." << endl;
    if (secretary.findPerson(idToFind)) {
        cout << idToFind << " was found in the secretary." << endl;
    } else {
        cout << idToFind << " was not found in the secretary." << endl;
    }
    
    cout << "---Ended Searching---" << endl;

    cout << endl;

    cin >> secretary;
    cout << secretary << endl;

    cout << "Total Persons: " << Person::getCount() << endl; // should be 5 at the end

    cout << endl;

    std::cout << "---Testing copy and equal secretaries---" << std::endl;
    Secretary equalSecretary = secretary;
    Secretary copySecretary(secretary);
    std::cout << "---Equal---" << std::endl;
    std::cout << equalSecretary << std::endl;
    std::cout << "---End Equal---" << std::endl;
    std::cout << "---Copy---" << std::endl;
    std::cout << copySecretary << std::endl;
    std::cout << "---End Copy---" << std::endl;
    
    cout << "Total Persons: " << Person::getCount() << endl; // should stay at 5 because we don't create persons

    return 0;
}
