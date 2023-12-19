#include "../include/Course.h"

Course::Course() : name(""), points(0), isMandatory(false), semester(0), id(idCounter)
{
    idCounter++;
}

Course::Course(std::string courseName, unsigned coursePoints, bool courseIsMandatory,
unsigned courseSemester, unsigned courseId) : name(courseName), points(coursePoints), isMandatory(courseIsMandatory),
semester(courseSemester), id(idCounter)
{
    idCounter++;
}

void Course::addProfessor(Professor* newProfessor)
{
    professors.push_back(newProfessor);
}

void Course::addStudent(Student* newStudent)
{
    unsigned grade = rand() % 11; // random grade from 0 to 10
    students.insert(std::pair<Student*, unsigned>(newStudent, grade));
    if (grade >= 5) // if student passed the course add him to studentsPassed
    {
        studentsPassed.insert(std::pair<Student*, unsigned>(newStudent, grade));
    }
    
}

void Course::printProfessors() {
    std::cout << "[Professors teaching " << name << "]" << std::endl;
    for(auto professor : professors)
    {
        std::cout << *professor << std::endl;
    }
}

void Course::printStudents() {
    std::cout << "[Students signed in " << name << "]" << std::endl;
    float averageGrade = 0;
    unsigned studentsPassedCounter = 0;
    for(auto student : students)
    {
        averageGrade += student.second;
        std::cout << *student.first << " Grade: " << student.second;
        if (student.second >= 5)
        {
            std::cout << " (Passed)" << std::endl;
            studentsPassedCounter++;
        }
        else
        {
            std::cout << " (Failed)" << std::endl;
        }
    }
    averageGrade /= students.size();
    std::cout << "Average grade: " << averageGrade << std::endl;
    std::cout << "Students passed: " << studentsPassedCounter << "/" << students.size() << "(" << (float)studentsPassedCounter/students.size()*100 << "%)" << std::endl;
}

void Course::printStudentsPassed() {
    std::cout << "[Students passed " << name << "]" << std::endl;
    for(auto student : studentsPassed)
    {
        std::cout << *student.first << " Grade: " << student.second << std::endl;
    }
}

std::ostream& operator<<(std::ostream& output, const Course& course) {
    output << "[ID: " << course.id << "] = Name: " << course.name
    << ", Points: " << course.points
    << ", Is Mandatory: " << course.isMandatory 
    << ", Semester: " << course.semester;
    return output;
}