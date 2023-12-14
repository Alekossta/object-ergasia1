#include "Secretary.h"
#include "Student.h"
#include "Professor.h"

#include <iostream>

using namespace std;

int Person::count = 0;

int main() {

    Secretary dit = Secretary("DIT");

    Student stud1 = Student("Alex", 19, 2022);
    Student stud2 = Student("Kostas", 19, 2023);

    Proffesor pilot = Proffesor("Pilot", 40);

    dit += stud1;
    dit += stud2;
    dit += pilot;

    std::cout << dit << endl;
    
    return 0;
}
