#include "../include/Secretary.h"
#include "../include/Student.h"
#include "../include/Professor.h"
#include "../include/Course.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int Person::count = 0;
unsigned Course::idCounter = 0;

Secretary dit = Secretary("DIT");

void displayMenu()
{
    cout << "\033[2J\033[1;1H"; // scroll down to give the effect of clearing the screen
    cout << "   ---Menu---" << endl;
    cout << "[1] add/modify/delete professors" << endl;
    cout << "[2] add/modify/delete students" << endl;
    cout << "[3] add/modify/delete courses" << endl;
    cout << "[4] define professors of a course" << endl;
    cout << "[5] enroll student in a course" << endl;
    cout << "[6] show and save students who passed course at a specific semester" << endl;
    cout << "[7] show professor statistics this semester" << endl;
    cout << "[8] show specific student grades" << endl;
    cout << "[9] show student eligible for graduation" << endl;
    cout << "[0] to exit" << endl;
    cout << "Enter a number: ";

    // cout << dit << endl;
    // dit.printCourses();
}

void handleOption(char option)
{
    switch (option)
    {
        case '0':
            break;
        case '1': 
        {
            cout << "[1] to add professor" << endl;
            cout << "[2] to edit professor" << endl;
            cout << "[3] to remove professor" << endl;
            cout << "Enter a number: ";

            unsigned userAnswer;
            cin >> userAnswer;

            dit.printProfessors();

            if (userAnswer == 1) {
                string name;
                int age;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                Professor prof = Professor(name, age);
                dit += prof;
            }
            else if (userAnswer == 2) {
                cout << "Enter professor id to modify: ";
                unsigned id;
                cin >> id;
                Professor* prof = dynamic_cast<Professor*>(dit.findPerson(id));
                if (prof != nullptr) {
                    cout << prof->getName() << endl;
                    cout << "Enter new name: ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
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
                Professor* prof = dynamic_cast<Professor*>(dit.findPerson(id));
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
        break;
        case '2':
        {
            cout << "[1] to add student" << endl;
            cout << "[2] to edit student" << endl;
            cout << "[3] to remove student" << endl;
            cout << "Enter a number: ";

            unsigned userAnswer;
            cin >> userAnswer;

            dit.printStudents();

            if (userAnswer == 1) {
                string name;
                int age;
                unsigned entryYear;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter entry year: ";
                cin >> entryYear;
                Student stud = Student(name, age, entryYear);
                dit += stud;
            }
            else if (userAnswer == 2) {
                cout << "Enter student id to modify: ";
                unsigned id;
                cin >> id;
                Student* stud = dynamic_cast<Student*>(dit.findPerson(id));
                if (stud != nullptr) {
                    cout << stud->getName() << endl;
                    cout << "Enter new name: ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    cout << stud->getAge() << endl;
                    cout << "Enter new age: ";
                    int age;
                    cin >> age;
                    stud->setName(name);
                    stud->setAge(age);
                }
                else {
                    cout << "Student not found" << endl;
                }
            }
            else if (userAnswer == 3) {
                cout << "Enter student id to remove: ";
                unsigned id;
                cin >> id;
                Student* stud = dynamic_cast<Student*>(dit.findPerson(id));
                if (stud != nullptr) {
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
        break;
        case '3':
        {
            cout << "[1] to add course" << endl;
            cout << "[2] to edit course" << endl;
            cout << "[3] to remove course" << endl;
            cout << "Enter a number: ";

            unsigned userAnswer;
            cin >> userAnswer;

            dit.printCourses();

            if (userAnswer == 1) {
                string name;
                unsigned points;
                bool isMandatory;
                unsigned semester;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter points: ";
                cin >> points;

                cout << "Enter isMandatory: ";
                cin >> isMandatory;

                cout << "Enter semester: ";
                cin >> semester;

                Course course = Course(name, points, isMandatory, semester, Course::getIdCounter());
                dit += course;
            }   
            else if (userAnswer == 2) {
                dit.printCourses();
                cout << "Enter course id to modify: ";
                unsigned id;
                cin >> id;
                Course* courseToModify = dit.getCourse(id);
                if (courseToModify != nullptr) {
                    cout << "Current points: " << courseToModify->getPoints() << endl;
                    cout << "Enter new points: ";
                    unsigned points;
                    cin >> points;
                    courseToModify->setPoints(points);

                    cout << "Current isMandatory status: " << courseToModify->getIsMandatory() << endl;
                    cout << "Enter new isMandatory status: ";
                    bool isMandatory;
                    cin >> isMandatory;
                    courseToModify->setIsMandatory(isMandatory);

                    cout << "Current semester: " << courseToModify->getSemester() << endl;
                    cout << "Enter new semester: ";
                    unsigned semester;
                    cin >> semester;
                    courseToModify->setSemester(semester);
                }
            }
            else if (userAnswer == 3) {
                dit.printCourses();
                cout << "Enter course id to remove: ";
                unsigned id;
                cin >> id;
                if (dit.getCourse(id) != nullptr) {
                    dit.removeCourse(id);
                }
                else {
                    cout << "Course not found" << endl;
                }
            }
            else {
                cout << "Invalid option" << endl;
            }      
        }
        break;
        case '4':
        {
            std::cout << "Pick course to define professors for: " << std::endl;
            dit.printCourses();
            unsigned id;
            cin >> id;
            Course* course = dit.getCourse(id);
            if(course != nullptr)
            {
                std::cout << "Choose from these professors: " << std::endl;
                dit.printProfessors();
                unsigned id;
                cin >> id;
                Professor* chosenProfessor = dynamic_cast<Professor*>(dit.findPerson(id));
                if(chosenProfessor != nullptr)
                {
                    std::cout << "Adding " << chosenProfessor->getName() << "..." << std::endl;
                    course->addProfessor(chosenProfessor);
                }
            }
        }
        break;
        case '5':
        {
            dit.printStudents();
            std::cout << "Please select student ";
            unsigned id;
            cin >> id;
            Student* student = dynamic_cast<Student*>(dit.findPerson(id));
            if(student != nullptr)
            {
                dit.printCourses();
                std::cout << "Select course to register to: ";
                unsigned id;
                cin >> id;
                Course* course = dit.getCourse(id);
                if(course != nullptr)
                {
                    course->addStudent(student);
                }
            }
        }
        break;
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

    Course oop = Course("OOP", 8, true, 3, Course::getIdCounter());
    dit += oop;

    Student stud1 = Student("Alex", 19, 2022);
    Student stud2 = Student("Kostas", 19, 2023);

    Professor pilot = Professor("Pilot", 40);

    dit += stud1;
    dit += stud2;
    dit += pilot;

    // std::cout << dit << endl;

    char userAnswer;
    while (userAnswer != '0')
    {
        displayMenu();
        std::cin >> userAnswer;
        handleOption(userAnswer);
    }

    std::cout << "Bye..." << std::endl;
    
    return 0;
}
