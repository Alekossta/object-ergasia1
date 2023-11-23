#include "Person.h"
#include "Secretary.h"
#include <iostream>
using namespace std;

int Person::count = 0;

int main() {
    Person p1(12, "george");
    Person p2;

    cin >> p2;

    cout << p2 << std::endl;
    cout << p1 << std::endl;

    return 1;
}
