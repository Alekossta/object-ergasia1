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
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

int Person::count = 0;
unsigned Course::idCounter = 0;
bool hasGradedStudents = false;

// 6 points to graduate not a realistic number 
// but usefull for debugging
Secretary dit = Secretary("DIT", 6, 4, 2023);

void emptyFolder(const fs::path& path) {
    if (fs::exists(path) && fs::is_directory(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            fs::remove_all(entry);
        }
    }
}

void displayMenu()
{
    cout << "\033[2J\033[1;1H"; // scroll down to give the effect of clearing the screen
    cout << "[Menu]" << endl << endl
    << dit.getYear() << " - " << (dit.getIsWinterSemester() ? "Winter" : "Summer") << " Semester"
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
    cout << "[0] to exit and save data" << endl;
    cout << "[x] to print everything" << endl; // REMOVE BEFORE SUBMISSION
    cout << "[r] to reset data" << endl;
    cout << (hasGradedStudents ? "[s] to switch semester" : "[s] to grade students") << endl;
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
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
            else if (userAnswer == 3) {
                cout << "Enter professor id to remove: ";
                unsigned id;
                cin >> id;
                Professor* prof = dynamic_cast<Professor*>(dit.findPerson(id));
                if (prof != nullptr) {
                    dit.removePerson(id);
                }
                else {
                    cout << "Professor not found" << endl;
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
            else {
                cout << "Invalid option" << endl;
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                cin.get();
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
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
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
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
            else if (userAnswer == 3) {
                cout << "Enter student id to remove: ";
                unsigned id;
                cin >> id;
                Student* stud = dynamic_cast<Student*>(dit.findPerson(id));
                if (stud != nullptr) {
                    dit.removePerson(id);
                }
                else {
                    cout << "Professor not found" << endl;
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
            else {
                cout << "Invalid option" << endl;
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                cin.get();
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
                if (semester > dit.getYearsOfStudy() * 2) {
                    cout << "Invalid semester" << endl;
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                    break;
                }

                Course course = Course(name, points, isMandatory, semester, Course::getIdCounter());
                dit += course;
            }   
            else if (userAnswer == 2) {
                dit.printCourses();
                cout << "Enter course id to modify: ";
                unsigned id;
                cin >> id;
                Course* courseToModify = dit.getAvailableCourse(id);
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

                Course* courseToRemove = dit.getAvailableCourse(id);
                if (courseToRemove != nullptr) {
                    // for every student currentlys enrolled in the course, remove the course from their current course
                    for (Student* student : courseToRemove->getStudents()) {
                        student->removeCourse(courseToRemove);
                    }
                    dit.getCourses().erase(id);

                    dit.removeCourse(id);
                }
                else {
                    cout << "Course not found" << endl;
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
            else {
                cout << "Invalid option" << endl;
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                cin.get();
            }      
        }
        break;
        case '4':
        {
            cout << "Pick course to define professors for: " << endl;
            dit.printCourses();
            unsigned id;
            cin >> id;
            Course* course = dit.getAvailableCourse(id);
            if(course != nullptr)
            {
                cout << "Choose from these professors: " << endl;
                dit.printProfessors();
                unsigned id;
                cin >> id;
                Professor* chosenProfessor = dynamic_cast<Professor*>(dit.findPerson(id));
                if(chosenProfessor != nullptr)
                {
                    course->addProfessor(chosenProfessor);
                    chosenProfessor->addCourse(course);
                }
            }
        }
        break;
        case '5':
        {
            if (hasGradedStudents) {
                cout << "Cannot enroll students until next semester starts" << endl;
                cout << endl << "Press enter to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
            dit.printStudents();
            cout << "Please select student ";
            unsigned id;
            cin >> id;
            Student* student = dynamic_cast<Student*>(dit.findPerson(id));
            if(student != nullptr)
            {
                dit.printCourses();
                cout << "Select course to register to: ";
                unsigned id;
                cin >> id;
                Course* course = dit.getAvailableCourse(id);

                if (course == nullptr) {
                    cout << "Course not available" << endl;
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                    break;
                }

                if (!course->hasProfessors()) {
                    cout << "No professors teaching this course" << endl;
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                    break;
                }

                unsigned yearDiff = dit.getYear() - student->getEntryYear();
                bool canRegister = (course->getSemester())/2 <= yearDiff;
                
                if(canRegister)
                {
                    if (student->hasPassedCourse(course)) {
                        cout << "Student has already passed this course" << endl;
                        cout << "Press enter to continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    } else if (student->hasEnrolledCourse(course)) {
                        cout << "Student has already enrolled in this course" << endl;
                        cout << "Press enter to continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    course->addStudent(student);
                    student->addCourse(course);
                }
                else
                {
                    cout << "Student cannot register yet" << endl;
                    cout << endl << "Press enter to continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
        }
        break;
        case '6':
        {
            dit.printCourses();
            cout << "Select a course: ";
            unsigned id;
            cin >> id;
            Course* course = dit.getAvailableCourse(id);

            // loop through all students and print the ones that have passed the course
            if(course != nullptr)
            {
                cout << "Students who have passed " << course->getName() << ": " << endl;

                unsigned year = dit.getYear();
                std::string courseName = course->getName();
                std::string filename = "data/passedStudents/" + std::to_string(year) + "_" + courseName + ".csv";
                std::ofstream outputFile(filename);

                if(outputFile.is_open())
                {
                    for(const auto& pair : dit.getPersons())
                    {
                        Student* student = dynamic_cast<Student*>(pair.second);
                        if(student != nullptr)
                        {
                            if(student->hasPassedCourse(course))
                            {
                                cout << student->getName() << endl; // to console
                                outputFile << student->getId() << "," << student->getName() << endl; // to file
                            }
                        }
                    }
                }
                else
                {
                    cout << "Could not create file" << endl;
                }
                
                outputFile.close();
            }
            else
            {
                cout << "Course not found" << endl;
            }

            cout << endl << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
        }
        break;
        case '7':
        {
            if(hasGradedStudents)
            {
                dit.printProfessors();
                cout << "Select a professor: ";
                unsigned id;
                cin >> id;
                Professor* professor = dynamic_cast<Professor*>(dit.findPerson(id));
                if(professor != nullptr)
                {
                    professor->printSemesterStats(dit.getIsWinterSemester());
                }
                else
                {
                    cout << "Professor not found" << endl;
                }
            }
            else
            {
                cout << "Students haven't been graded yet to show stats for this semester." << endl;
            }
            cout << endl << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
        }
        break;
        case '8':
        {
            dit.printStudents();
            cout << "Select a student to print grades for: ";
            unsigned id;
            cin >> id;
            Student* student = dynamic_cast<Student*>(dit.findPerson(id));
            if(student != nullptr)
            {
                cout << "[Current semester courses of " << student->getName() << "]" << endl;
                if (hasGradedStudents)
                {
                    student->printCurrentSemesterGrades();
                } 
                else
                {
                    cout << "Current semester grades not available yet" << endl;
                }

                student->printPassedGrades();
            }
            else
            {
                cout << "Did not find student" << endl;
            }

            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
        }
        break;
        case '9':
        {
            cout << "[Students eligible for graduation]" << endl;
            for(const auto& pair : dit.getPersons())
            {
                Student* student = dynamic_cast<Student*>(pair.second);
                if(student != nullptr)
                {
                    if(dit.canGraduate(student))
                    {
                        cout << student->getName() << " can graduate! [" << student->getAverage() << "]" << endl;
                    }
                }
            }
            cout << endl << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
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
            // will set firstTimeRunning to true
            std::ofstream firstTimeRunningFileOutput("data/firstTimeRunning.csv", std::ios::out | std::ios::trunc);
            if(firstTimeRunningFileOutput.is_open())
            {
                firstTimeRunningFileOutput << "true";
            }   
            else
            {
                cout << "Failed to open file firstTimeRunning.csv" << endl;
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
                cout << "Failed to open file timeData.csv" << endl;
            }

            timeDataOutput.close();

            // will make all other files in data empty 
            // (given that we exit the program with 0 and save functions gets called)
            dit.getCourses().clear();
            dit.getPersons().clear();

            // make passedStudents folder empty
            emptyFolder("data/passedStudents");

            cout << "Data reset" << endl;
            cout << endl << "Exit program to save changes? (Y/N): ";
            char userInput;
            cin >> userInput;
            if(userInput == 'y' || userInput == 'Y')
            {
                exit(0);
            }
        }
        break;
        case 's':
        {
            if(!hasGradedStudents)
            {
                cout << "Do you want to grade students manually? (Y/N): ";
                char userInput;
                cin >> userInput;
                if(userInput == 'y' || userInput == 'Y')
                {
                    dit.printProfessors();
                    cout << "Please enter your id: ";
                    unsigned id;
                    cin >> id;
                    Professor* professor = dynamic_cast<Professor*>(dit.findPerson(id));
                    if(professor)
                    {
                        professor->printCourses();
                        cout << "Enter course id you want to grade: ";
                        unsigned id;
                        cin >> id;
                        Course* course = professor->getCourse(id);
                        if(course)
                        {
                            for(Student* student : course->getStudents())
                            {
                                if(student)
                                {
                                    cout << "Grade " << student->getName() << ": ";
                                    unsigned grade;
                                    cin >> grade;
                                    student->setGrade(course, grade);
                                }
                            }
                        }
                        else
                        {
                            cout << "Could not find course" << endl;
                        }
                    }
                    else
                    {
                        cout << "Could not find professor" << endl;
                    }
                }
                else
                {
                    // grade all students randomly
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
            }
            else
            {
                // age people by one year
                // to do that randomly, we will convert the students name to an int, and check if it is even or odd
                // if even, we will say their birthday is in the winter semester, else in the summer semester

                for(const auto& pair : dit.getPersons())
                {
                    Person* person = dynamic_cast<Person*>(pair.second);
                    if(person != nullptr)
                    {
                        int nameToInt = 0;
                        for (char c : person->getName()) {
                            nameToInt += c;
                        }
                        if (nameToInt % 2 == 0 && dit.getIsWinterSemester()) {
                            person->setAge(person->getAge() + 1);
                        } else if (nameToInt % 2 != 0 && !dit.getIsWinterSemester()) {
                            person->setAge(person->getAge() + 1);
                        }
                    }
                }

                // switch semester

                dit.switchSemester();
                hasGradedStudents = false;
            }
        }
        break;
        default:
            cout << "Invalid option" << endl;
    }
}

bool stringToBool(const std::string& str) {
    if (str == "true") {
        return true;
    } else if (str == "false") {
        return false;
    }
    // Handle error or return a default value
    cerr << "Invalid string for conversion to bool: " << str << endl;
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
        coursesFile.close();
    }
    else
    {
        cout << "Error in opening courses file" << endl;
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


            Professor* professorAdded;
            if(loadIds)
            {
                Professor newProfessor = Professor(name, age, id);
                dit += newProfessor;
                professorAdded = dynamic_cast<Professor*>(dit.findPerson(newProfessor.getId()));

                // load professor-course relations
                if(professorAdded != nullptr)
                {
                    // for every other value in the line, add the professor to the course with the id equal to the value
                    while (getline(lineStream, value, ',')) {
                        Course* course = dit.getAvailableCourse(static_cast<unsigned>(std::stoul(value)));
                        if (course != nullptr) {
                            course->addProfessor(professorAdded);
                            static_cast<Professor*>(dit.findPerson(professorAdded->getId()))->addCourse(course);
                        }
                        else {
                            cout << "Course not found" << endl;
                        }
                    }
                }
            }
            else
            {
                Professor newProfessor = Professor(name, age);
                dit += newProfessor;
                professorAdded = dynamic_cast<Professor*>(dit.findPerson(newProfessor.getId()));
            }
        }
        profsFile.close();
    }
    else
    {
        cout << "Error in opening professors file" << endl;
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

                // load student-course relations
                if(studentAdded != nullptr)
                {
                    // for every other value in the line, add the student to the course with the id equal to the value
                    while (getline(lineStream, value, ',')) {
                        // get course with id equal to value
                        Course* course = dit.getAvailableCourse(static_cast<unsigned>(std::stoul(value)));
                        if (course != nullptr) {
                            // get grade from next value
                            getline(lineStream, value, ',');
                            unsigned grade = static_cast<unsigned>(std::stoul(value));

                            studentAdded->addPassedCourse(course, grade);
                        }
                    }
                }
            }
            else
            {
                Student newStudent = Student(name, age, entryYear);
                dit += newStudent;
                studentAdded = dynamic_cast<Student*>(dit.findPerson(newStudent.getId()));
            }
        }
        studsFile.close();
    }
    else
    {
        cout << "Error in opening students file" << endl;
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
            cout << "Error writing to file first time running file" << endl;
        }
    }
    else
    {
        loadCourses("data/courses.csv", true);
        loadProfessors("data/professors.csv", true);
        loadStudents("data/students.csv", true);

        // load time data
        std::ifstream timeDataFile("data/timeData.csv");
        std::string line, value;

        if(timeDataFile.is_open())
        {
            getline(timeDataFile, line);

            std::stringstream lineStream(line);

            // year
            getline(lineStream, value, ',');
            unsigned year = static_cast<unsigned>(std::stoul(value));

            // is winter semester
            getline(lineStream, value, ',');
            bool isWinterSemester = stringToBool(value);

            dit.setYear(year);
            dit.setIsWinterSemester(isWinterSemester);

            timeDataFile.close();
        }
        else
        {
           cout << "Error in opening time data file" <<endl;
        }

    }
}

std::string boolToString(bool value)
{
    if(value)
    {
        return "true";
    }
    else
    {
        return "false";
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
                << boolToString(course->getIsMandatory()) << ','
                << course->getSemester()
                << endl;
            }
        }
    }
    else
    {
        cout << "Error: File could not be opened" << endl;
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
                << student->getEntryYear();

                // save courses passed and their grades
                for(StudentCourse studentCourse : student->getPassedCourses())
                {
                    Course* course = studentCourse.course;
                    if(course != nullptr)
                    {
                        studentsFile << ',' << course->getId() << ',' << studentCourse.grade;
                    }
                }
                studentsFile << endl;
            }
        }
    }
    else
    {
        cout << "Error: File could not be opened" << endl;
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
                << professor->getAge();

                // save courses teaching
                for(Course* course : professor->getCourses())
                {
                    if(course != nullptr)
                    {
                        professorsFile << ',' << course->getId();
                    }
                }
                professorsFile << endl;
            }
        }
    }
    else
    {
        cout << "Error: File could not be opened" << endl;
    }

    // Save time data

    std::ofstream timeDataFile("data/timeData.csv");
    if(timeDataFile.is_open()) {
        timeDataFile 
        << dit.getYear() << ','
        << (dit.getIsWinterSemester() ? "true" : "false")
        << endl;
    }
    else
    {
        cout << "Error: File could not be opened" << endl;
    }

}

int main() {

    try {
        loadData();
    }
    catch (const std::invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl << "Continuing with incomplete data..." << endl;
    }

    char userAnswer;
    while (userAnswer != '0')
    {
        displayMenu();
        cin >> userAnswer;
        handleOption(userAnswer);
    }

    saveData();
    
    return 0;
}