#include "../include/Student.h"
#include "../include/Course.h"

Student::Student(const std::string& startingName, int startingAge,
unsigned studentEntryYear) : Person(startingName, startingAge), entryYear(studentEntryYear)
{
    
}

void Student::printPerson() const 
{
    std::cout << "Student: ";
    Person::printPerson();
}

void Student::printCurrentSemesterGrades()
{
    for(StudentCourse studentCourse : currentSemesterCourses)
    {
        Course* course = studentCourse.course;
        if(course != nullptr)
        {
            std::cout << course->getName() << " = " << studentCourse.grade << std::endl;
        }
    }
}

void Student::printAllGrades()
{
    for(StudentCourse studentCourse : allCourses)
    {
        Course* course = studentCourse.course;
        if(course != nullptr)
        {
            std::cout << course->getName() << " = " << studentCourse.grade << std::endl;
        }
    }
}

void Student::addCourse(Course* newCourse)
{
    StudentCourse studentCourse;
    studentCourse.course = newCourse;
    studentCourse.grade = 0;
    currentSemesterCourses.push_back(studentCourse);
    allCourses.push_back(studentCourse);
}