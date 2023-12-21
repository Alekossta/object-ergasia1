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
    for(StudentCourse studentCourse : passedCourses)
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
        for(StudentCourse& studentCourse : currentSemesterCourses)
        {
            if(studentCourse.course == course)
            {
                studentCourse.grade = grade;
                
                if(grade >= 5) {
                    passedCourses.push_back(studentCourse);
                    if (course->getIsMandatory()) mandatoryCoursesPassed++;
                    points += course->getPoints();
                }
                break;
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
}

unsigned Student::getGradeForCourse(Course* course)
{  
    for(StudentCourse currentCourse : passedCourses)
    {
        if(currentCourse.course == course)
        {
            return currentCourse.grade;
        }
    }

    for (StudentCourse currentCourse : currentSemesterCourses)
    {
        if (currentCourse.course == course)
        {
            return currentCourse.grade;
        }
    }

    return 11;
}

bool Student::hasPassedCourse(Course* course) {
    for(StudentCourse currentCourse : passedCourses) {
        if(currentCourse.course == course) return true;
    }
    return false;
}

bool Student::hasEnrolledCourse(Course* course) {
    for(StudentCourse currentCourse : currentSemesterCourses) {
        if(currentCourse.course == course) return true;
    }
    return false;
}