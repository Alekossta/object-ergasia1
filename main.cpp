#include "Person.h"
#include "Secretary.h"
#include <iostream>
using namespace std;

int Person::count = 0;

int main() {
    // Δημιουργία και διαχείριση αντικειμένων
    Secretary secretary;
    Person p1(25, "John"), p2(30, "Jane");

    secretary = secretary + p1;
    secretary = secretary + p2;

    std::cout << "Total Persons: " << Person::getCount() << std::endl;
    std::cout << secretary;

    // Άλλες λειτουργίες
}
