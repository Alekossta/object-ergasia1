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
    students.push_back(newStudent);    
}

void Course::printProfessors() {
    std::cout << "[Professors teaching " << name << "]" << std::endl;
    for(auto professor : professors)
    {
        std::cout << *professor << std::endl;
    }
}

void Course::printStats()
{
    unsigned gradeSum = 0;
    unsigned passed = 0;
    for(Student* student : students)
    {
        unsigned studentGrade = student->getGradeForCourse(this);
        gradeSum += studentGrade;
        if(studentGrade >= 5)
        {
            passed++;
        }
    }

    float average = (float)gradeSum / students.size();
    std::cout << "Average is: " << average << std::endl;
    std::cout << "Student that passed are: " << passed << std::endl;   
}

std::ostream& operator<<(std::ostream& output, const Course& course) {
    output << "[ID: " << course.id << "] = Name: " << course.name
    << ", Points: " << course.points
    << ", Is Mandatory: " << course.isMandatory 
    << ", Semester: " << course.semester;
    return output;
}