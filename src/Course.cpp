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

std::ostream& operator<<(std::ostream& output, const Course& course) {
    output << "[id:" << course.id << "] = Name: " << course.name 
    << ", Points: " << course.points
    << ", Is mandatory: " << course.isMandatory
    << ", Semester: " << course.semester
    << ", Professors: ";
    for(Professor* professor : course.professors)
    {
        std::cout << *professor;
    }
    return output;
}