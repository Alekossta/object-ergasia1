#include "../include/Student.h"
#include "../include/Course.h"

Student::Student(const std::string& startingName, int startingAge,
unsigned studentEntryYear) : Person(startingName, startingAge), entryYear(studentEntryYear), points(0),
mandatoryCoursesPassed(0)
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

void Student::setGrade(Course* course, unsigned grade)
{
    if(course != nullptr)
    {
        for(StudentCourse currentCourse : allCourses)
        {
            if(currentCourse.course == course)
            {
                std::cout << "Set grade" << std::endl;
                currentCourse.grade = grade;
                std::cout << currentCourse.grade;
            }
        }
    }
}

void Student::addCourse(Course* newCourse)
{
    StudentCourse studentCourse;
    studentCourse.course = newCourse;
    studentCourse.grade = 11;
    currentSemesterCourses.push_back(studentCourse);
    allCourses.push_back(studentCourse);
}

unsigned Student::getGradeForCourse(Course* course)
{  
    for(StudentCourse currentCourse : allCourses)
    {
        if(currentCourse.course == course)
        {
            return currentCourse.grade;
        }
    }

    return 11;
}