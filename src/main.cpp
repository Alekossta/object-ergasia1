#include "../include/Secretary.h"
#include "../include/Student.h"
#include "../include/Professor.h"

#include <iostream>

using namespace std;

int Person::count = 0;
Secretary dit = Secretary("DIT");

void displayMenu()
{
    std::cout << "---Menu, enter a number---" << std::endl;
    std::cout << "1 change professors" << std::endl;
    std::cout << "2 change students" << std::endl;
    std::cout << "3 change courses" << std::endl;
    std::cout << "4 define professors" << std::endl;
    std::cout << "5 register student in a course" << std::endl;
    std::cout << "6 show and save students who passed course at a specific semester" << std::endl;
    std::cout << "7 show professor statistics this semester" << std::endl;
    std::cout << "8 show specific student grades" << std::endl;
    std::cout << "9 show student eligible for graduation" << std::endl;
    std::cout << "0 to exit" << std::endl;
}

void handleOption(char option)
{
    if(option == '0') return;

    if(option == '1')
    {

    }
    else if(option == '2')
    {

    }
    else if(option == '3')
    {

    }
    else if(option == '4')
    {

    }
    else if(option == '5')
    {

    }
    else if(option == '6')
    {

    }
    else if(option == '7')
    {

    }
    else if(option == '8')
    {

    }
    else if(option == '9')
    {

    }
    else
    {
        std::cout << "Please enter a valid option" << std::endl;
    }
}

int main() {
    Student stud1 = Student("Alex", 19, 2022);
    Student stud2 = Student("Kostas", 19, 2023);

    Proffesor pilot = Proffesor("Pilot", 40);

    dit += stud1;
    dit += stud2;
    dit += pilot;

    std::cout << dit << endl;

    std::cout << "Use menu? (Y/N)" << std::endl;
    char userAnswer;
    std::cin >> userAnswer;
    if(userAnswer == 'Y' || userAnswer == 'y')
    {
        while (userAnswer != '0')
        {
            displayMenu();
            std::cin >> userAnswer;
            handleOption(userAnswer);
        }
    }

    std::cout << "Bye..." << std::endl;
    
    return 0;
}
