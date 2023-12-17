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

std::ostream& operator<<(std::ostream& output, const Course& course) {
    output << "---" << course.id << " " << course.name << "---" << std::endl;
    output << "Course info: " << "Points = " << course.points <<
     ", Is Mandatory = " << course.isMandatory << ", Semester = " << course.semester << std::endl;
    output << "Professors teaching " << course.name << std::endl;
    for(Professor* professor : course.professors)
    {
        std::cout << *professor << std::endl;
    }
    output << "Students signed in " << course.name << std::endl;
    for(Student* student : course.students)
    {
        std::cout << *student << std::endl;
    }
    return output;
}