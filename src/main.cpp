#include "../include/Secretary.h"
#include "../include/Student.h"
#include "../include/Professor.h"
#include "../include/Course.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int Person::count = 0;
unsigned Course::idCounter = 0;
bool hasGradedStudents = false;

Secretary dit = Secretary("DIT", 40, 160, 4, 2023);

void displayMenu()
{
    cout << "\033[2J\033[1;1H"; // scroll down to give the effect of clearing the screen
    cout << ">>>Menu" << endl << endl
    << dit.getYear() << " " << (dit.getIsWinterSemester() ? "Winter" : "Summer") << " Semester"
    << " (" << (hasGradedStudents ? "Graded" : "Not Graded") << ")" << endl;
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
    cout << "[x] to print everything (for debugging)" << endl; // REMOVE BEFORE SUBMISSION
    cout << "[r] to reset data" << endl;
    cout << (hasGradedStudents ? "[s] to switch semester" : "[s] to grade students") << endl;
    cout << "[a] to auto load profs/students to courses(for debugging)" << endl; // REMOVE BEFORE SUBMISSION
    cout << "Enter a number: ";
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
                if (entryYear > dit.getYear()) {
                    cout << "Invalid entry year" << endl;
                    break;
                }
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
                    chosenProfessor->addCourse(course);
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
                unsigned yearDiff = dit.getYear() - student->getEntryYear();
                bool canRegister = (course->getSemester())/2 <= yearDiff;
                
                if(canRegister)
                {
                    if (student->hasPassedCourse(course)) {
                        std::cout << "Student has already passed this course" << std::endl;
                        std::cout << "Press enter to continue..." << std::endl;
                        cin.ignore();
                        cin.get();
                        break;
                    } else if (student->hasEnrolledCourse(course)) {
                        std::cout << "Student has already enrolled in this course" << std::endl;
                        std::cout << "Press enter to continue..." << std::endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    if(course != nullptr)
                    {
                        course->addStudent(student);
                        student->addCourse(course);
                    }
                }
                else
                {
                    std::cout << "Student cannot register yet" << std::endl;
                }
            }
        }
        break;
        case '6':
        {
            // not ready yet

            dit.printCourses();
            std::cout << "Select course to show and save stats of passed students: ";
            unsigned id;
            cin >> id;
            Course* course = dit.getCourse(id);
            if (course == nullptr) {
                std::cout << "Course not found" << std::endl;
                break;
            }
        }
        break;
        case '7':
        {
            if(hasGradedStudents)
            {
                dit.printProfessors();
                std::cout << "Select a professor: ";
                unsigned id;
                cin >> id;
                Professor* professor = dynamic_cast<Professor*>(dit.findPerson(id));
                if(professor != nullptr)
                {
                    professor->printSemesterStats(dit.getIsWinterSemester());
                }
                else
                {
                    std::cout << "Professor not found" << std::endl;
                }

                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                cin.get();
            }
            else
            {
                std::cout << "Students haven't been graded yet to show stats for this semester." << std::endl;
            }
        }
        break;
        case '8':
        {
            dit.printStudents();
            std::cout << "Select a student to print grades for: ";
            unsigned id;
            cin >> id;
            Student* student = dynamic_cast<Student*>(dit.findPerson(id));
            if(student != nullptr)
            {
                if (hasGradedStudents)
                {
                    student->printCurrentSemesterGrades();
                } 
                else
                {
                    std::cout << "Current semester grades not available yet" << std::endl;
                }

                student->printAllGrades();
            }
            else
            {
                std::cout << "Did not find student" << std::endl;
            }

            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
        }
        break;
        case '9':
        {
            for(const auto& pair : dit.getPersons())
            {
                Student* student = dynamic_cast<Student*>(pair.second);
                if(student != nullptr)
                {
                    if(dit.canGraduate(student))
                    {
                        std::cout << student->getName() << " can graduate!" << std::endl;
                    }
                }
            }
        }
        break;
        case 'x':
        {
            dit.printProfessors();
            dit.printStudents();
            dit.printCourses();

            // for each course print professors using the course's printProfessors() method
            for (const auto& pair : dit.getCourses()) {
                Course* course = pair.second;
                course->printProfessors();
            }
            cout << endl;

            // for each course print students using the course's printStudents() method
            for (const auto& pair : dit.getCourses()) {
                Course* course = pair.second;
                course->printStudents();
            }
            cout << endl;

            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
        }
        break;
        case 'r': 
        {
           
            // will se firstTimeRunning to true

            std::ofstream firstTimeRunningFileOutput("data/firstTimeRunning.csv", std::ios::out | std::ios::trunc);
            if(firstTimeRunningFileOutput.is_open())
            {
                firstTimeRunningFileOutput << "true";
            }   
            else
            {
                std::cout << "Failed to open file firstTimeRunning.csv" << std::endl;
            }

            firstTimeRunningFileOutput.close();

            
            // will set date back to 2023 winter semester
            std::ofstream timeDataOutput("data/timeData.csv", std::ios::out | std::ios::trunc);
            if(timeDataOutput.is_open())
            {
                timeDataOutput << 2023 << ',' << "true";
            }   
            else
            {
                std::cout << "Failed to open file timeData.csv" << std::endl;
            }

            timeDataOutput.close();

            // will make all other files in data empty

            dit.getCourses().clear();
            dit.getPersons().clear();

            // std::ofstream coursesOutput("data/courses.csv", std::ios::out | std::ios::trunc);
            // if(coursesOutput.is_open())
            // {
            //     coursesOutput << "";
            // }
            // else
            // {
            //     std::cout << "Failed to open file courses.csv" << std::endl;
            // }

            // coursesOutput.close();

            // std::ofstream studentsOutput("data/courses.csv", std::ios::out | std::ios::trunc);
            // if(studentsOutput.is_open())
            // {
            //     studentsOutput << "";
            // }
            // else
            // {
            //     std::cout << "Failed to open file courses.csv" << std::endl;
            // }

            // studentsOutput.close();

            // std::ofstream professorsOutput("data/courses.csv", std::ios::out | std::ios::trunc);
            // if(professorsOutput.is_open())
            // {
            //     professorsOutput << "";
            // }
            // else
            // {
            //     std::cout << "Failed to open file courses.csv" << std::endl;
            // }

            // professorsOutput.close();
        }
        break;
        case 's':
        {
            if(!hasGradedStudents)
            {
                // grade students using student's setGrade() with a random grade
                for(const auto& pair : dit.getPersons())
                {
                    Student* student = dynamic_cast<Student*>(pair.second);
                    if(student != nullptr)
                    {
                        for(const auto& course : student->getCurrentSemesterCourses())
                        {
                            student->setGrade(course.course, rand() % 11);
                        }
                    }
                }

                hasGradedStudents = true;
            }
            else
            {
                dit.switchSemester();
                hasGradedStudents = false;
            }
        }
        break;
        case 'a':
        {
            if (dit.getIsWinterSemester()) {
                // add lygizou and pilot to oop
                Course* oop = dit.getCourse(0);
                oop->addProfessor(dynamic_cast<Professor*>(dit.findPerson(3)));
                oop->addProfessor(dynamic_cast<Professor*>(dit.findPerson(4)));
                dynamic_cast<Professor*>(dit.findPerson(3))->addCourse(oop);
                dynamic_cast<Professor*>(dit.findPerson(4))->addCourse(oop);

                // add alex to oop
                Student* alex = dynamic_cast<Student*>(dit.findPerson(0));
                oop->addStudent(alex);
                alex->addCourse(oop);


                // add giannis to oop and itp
                Student* giannis = dynamic_cast<Student*>(dit.findPerson(2));
                oop->addStudent(giannis);
                giannis->addCourse(oop);
            }
            else {
                // add takis to itp
                Course* itp = dit.getCourse(1);
                itp->addProfessor(dynamic_cast<Professor*>(dit.findPerson(5)));
                dynamic_cast<Professor*>(dit.findPerson(5))->addCourse(itp);

                // add kostas to itp
                Student* kostas = dynamic_cast<Student*>(dit.findPerson(1));
                itp->addStudent(kostas);
                kostas->addCourse(itp);

                // add alex to itp
                Student* alex = dynamic_cast<Student*>(dit.findPerson(0));
                itp->addStudent(alex);
                alex->addCourse(itp);
            }
        }
        break;
        default:
            std::cout << "Invalid option" << std::endl;
    }
}

bool stringToBool(const std::string& str) {
    if (str == "true") {
        return true;
    } else if (str == "false") {
        return false;
    }
    // Handle error or return a default value
    std::cerr << "Invalid string for conversion to bool: " << str << std::endl;
    return false;
}

void loadCourses(std::string courseFileName, bool loadIds)
{
    std::ifstream coursesFile(courseFileName);
    std::string line, value;

    if(coursesFile.is_open())
    {
        while (getline(coursesFile, line)) {

            std::stringstream lineStream(line);

            unsigned id;
            if(loadIds)
            {
                // id
                getline(lineStream, value, ',');
                id = static_cast<unsigned>(std::stoul(value));
            } 

            // name
            getline(lineStream, value, ',');
            std::string name = value;

            // points
            getline(lineStream, value, ',');
            unsigned points = static_cast<unsigned>(std::stoul(value));
            
            // is mandatory
            getline(lineStream, value, ',');
            bool isMandatory = stringToBool(value);

            // semester
            getline(lineStream, value, ',');
            unsigned semester = static_cast<unsigned>(std::stoul(value));

            if(loadIds)
            {
                Course newCourse = Course(name, points, isMandatory, semester, id);
                dit += newCourse;
            }
            else
            {
                Course newCourse = Course(name, points, isMandatory, semester);
                dit += newCourse;
            }
        }
        cout << "Loaded courses" << endl;
        coursesFile.close();
    }
    else
    {
        std::cout << "Error in opening courses file" << std::endl;
    }
}

void loadProfessors(std::string professorsFileName, bool loadIds)
{
    std::ifstream profsFile(professorsFileName);
    std::string line, value;

    if(profsFile.is_open())
    {
        while (getline(profsFile, line)) {

            std::stringstream lineStream(line);

            unsigned id;
            if(loadIds)
            {
                // id
                getline(lineStream, value, ',');
                id = static_cast<unsigned>(std::stoul(value));
            } 

            // name
            getline(lineStream, value, ',');
            std::string name = value;

            // age
            getline(lineStream, value, ',');
            unsigned age = static_cast<unsigned>(std::stoul(value));

            if(loadIds)
            {
                Professor newProfessor = Professor(name, age, id);
                dit += newProfessor;
            }
            else
            {
                Professor newProfessor = Professor(name, age);
                dit += newProfessor;
            }
        }
        cout << "Loaded professors" << endl;
        profsFile.close();
    }
    else
    {
        std::cout << "Error in opening professors file" << std::endl;
    }

}

void loadStudents(std::string studentsFileName, bool loadIds)
{
    std::ifstream studsFile(studentsFileName);
    std::string line, value;

    if(studsFile.is_open())
    {
        while (getline(studsFile, line)) {

            std::stringstream lineStream(line);

            unsigned id;
            if(loadIds)
            {
                // id
                getline(lineStream, value, ',');
                id = static_cast<unsigned>(std::stoul(value));
            } 

            // name
            getline(lineStream, value, ',');
            std::string name = value;

            // age
            getline(lineStream, value, ',');
            unsigned age = static_cast<unsigned>(std::stoul(value));

            // entry year
            getline(lineStream, value, ',');
            unsigned entryYear = static_cast<unsigned>(std::stoul(value));

            Student* studentAdded;
            if(loadIds)
            {
                Student newStudent = Student(name, age, id);
                dit += newStudent;
                studentAdded = dynamic_cast<Student*>(dit.findPerson(newStudent.getId()));
            }
            else
            {
                Student newStudent = Student(name, age, entryYear);
                dit += newStudent;
                studentAdded = dynamic_cast<Student*>(dit.findPerson(newStudent.getId()));
            }

            if(studentAdded != nullptr)
            {
                // for every other value in the line, add the student to the course with the id equal to the value
                while (getline(lineStream, value, ',')) {
                    Course* course = dit.getCourse(static_cast<unsigned>(std::stoul(value)));
                    if (course != nullptr) {
                        course->addStudent(studentAdded);
                        static_cast<Student*>(dit.findPerson(studentAdded->getId()))->addCourse(course);

                        cout << "Added student " << studentAdded->getName() << " to course " << course->getName() << endl;
                    }
                    else {
                        cout << "Course not found" << endl;
                    }
                }
            }
        }
        cout << "Loaded students" << endl;
        studsFile.close();
    }
    else
    {
        std::cout << "Error in opening students file" << std::endl;
    }
}

void loadData()
{
    // See if we are running for the first time
    std::ifstream firstTimeRunningFileInput("data/firstTimeRunning.csv");
    std::string line;

    getline(firstTimeRunningFileInput, line);

    bool isFirstTime = stringToBool(line);
    if(isFirstTime)
    {
        loadCourses("data/startingData/startingCourses.csv", false);
        loadProfessors("data/startingData/startingProfessors.csv", false);
        loadStudents("data/startingData/startingStudents.csv", false);

        firstTimeRunningFileInput.close();

        // Open the file in write mode, which will clear its contents
        std::ofstream firstTimeRunningFileOutput("data/firstTimeRunning.csv", std::ios::out | std::ios::trunc);

        if(firstTimeRunningFileOutput.is_open())
        {
            firstTimeRunningFileOutput << "false";
        }
        else
        {
            std::cout << "Error writing to file first time running file" << std::endl;
        }
    }
    else
    {
        loadCourses("data/courses.csv", true);
        loadProfessors("data/professors.csv", true);
        loadStudents("data/students.csv", true);
    }
}

void saveData()
{
    // Save courses

    std::ofstream coursesFile("data/courses.csv");
    if(coursesFile.is_open()) {
        for(auto coursePair : dit.getCourses())
        {
            Course* course = coursePair.second;
            if(course != nullptr)
            {
                coursesFile << course->getId() << ','
                << course->getName() << ','
                << course->getPoints() << ','
                << course->getIsMandatory() << ','
                << course->getSemester()
                << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Error: File could not be opened" << std::endl;
    }

    // Save students

    std::ofstream studentsFile("data/students.csv");
    if(studentsFile.is_open()) {
        for(auto personPair : dit.getPersons())
        {
            Student* student = dynamic_cast<Student*>(personPair.second);
            if(student != nullptr)
            {
                studentsFile << student->getId() << ','
                << student->getName() << ','
                << student->getAge() << ','
                << student->getEntryYear()
                << std::endl;

                // save courses signed up to ...
            }
        }
    }
    else
    {
        std::cout << "Error: File could not be opened" << std::endl;
    }

    // Save professors

    std::ofstream professorsFile("data/professors.csv");
    if(professorsFile.is_open()) {
        for(auto personPair : dit.getPersons())
        {
            Professor* professor = dynamic_cast<Professor*>(personPair.second);
            if(professor != nullptr)
            {
                professorsFile << professor->getId() << ','
                << professor->getName() << ','
                << professor->getAge()
                << std::endl;

                // save courses teaching ...
            }
        }
    }
    else
    {
        std::cout << "Error: File could not be opened" << std::endl;
    }
}

int main() {

    try {
        loadData();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl << "Continuing with incomplete data..." << std::endl;
    }

    char userAnswer;
    while (userAnswer != '0')
    {
        displayMenu();
        std::cin >> userAnswer;
        handleOption(userAnswer);
    }

    saveData();
    
    return 0;
}