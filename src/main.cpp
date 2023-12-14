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
    // switch statement up to 10
    switch (option)
    {
        case '0':
            break;
        case '1': {
                cout << "1 to add professor" << endl;
                cout << "2 to edit professor" << endl;
                cout << "3 to remove professor" << endl;

                unsigned userAnswer;
                cin >> userAnswer;

                if (userAnswer == 1) {
                    string name;
                    int age;
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter age: ";
                    cin >> age;
                    Professor prof = Professor(name, age);
                    dit += prof;
                }
                else if (userAnswer == 2) {
                    cout << "Enter professor id to modify: ";
                    unsigned id;
                    cin >> id;
                    Professor* prof = static_cast<Professor*>(dit.findPerson(id));
                    if (prof != nullptr) {
                        cout << prof->getName() << endl;
                        cout << "Enter new name: ";
                        string name;
                        cin >> name;
                        cout << prof->getAge() << endl;
                        cout << "Enter new age: ";
                        int age;
                        cin >> age;
                        prof->setName(name);
                        prof->setAge(age);
                    }
                    else {
                        cout << "Professor not found" << endl;
                    }
                }
                else if (userAnswer == 3) {
                    cout << "Enter professor id to remove: ";
                    unsigned id;
                    cin >> id;
                    Professor* prof = static_cast<Professor*>(dit.findPerson(id));
                    if (prof != nullptr) {
                        dit.getPersons().erase(id);
                    }
                    else {
                        cout << "Professor not found" << endl;
                    }
                }
                else {
                    cout << "Invalid option" << endl;
                }
            }
        case '2':
            // placeholder
        case '3':
            // placeholder
        case '4':
            // placeholder
        case '5':
            // placeholder
        case '6':
            // placeholder
        case '7':
            // placeholder
        case '8':
            // placeholder
        case '9':   
            // placeholder
        
        default:
            std::cout << "Invalid option" << std::endl;
    }
}

int main() {
    Student stud1 = Student("Alex", 19, 2022);
    Student stud2 = Student("Kostas", 19, 2023);

    Professor pilot = Professor("Pilot", 40);

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
