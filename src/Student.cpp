#include "../include/Student.h"
#include "../include/Course.h"

Student::Student(const std::string& startingName, unsigned startingAge,
unsigned studentEntryYear) : Person(startingName, startingAge), entryYear(studentEntryYear)
{
    
}

Student::Student(const std::string& startingName, unsigned startingAge,
unsigned studentEntryYear, unsigned startingId) : Person(startingName, startingAge, startingId),
entryYear(studentEntryYear)
{

}

void Student::printPerson() const 
{
    std::cout << "Student: ";
    Person::printPerson();
    std::cout << "Entry year: " << entryYear;
}

void Student::printCurrentSemesterGrades()
{
    if(currentSemesterCourses.size() > 0)
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
    else
    {
        std::cout << getName() << " has not signed up for a course this semester" << std::endl;
    }
}

void Student::printPassedGrades()
{
    std::cout << "[All passed courses of " << getName() << "]" << std::endl;
    if(passedCourses.size() > 0)
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
    else
    {
        std::cout << getName() << " has no passed courses" << std::endl;
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

void Student::addPassedCourse(Course* newCourse, unsigned grade)
{
    StudentCourse studentCourse;
    studentCourse.course = newCourse;
    studentCourse.grade = grade;
    passedCourses.push_back(studentCourse);
}

void Student::removeCourse(Course* course)
{
    for (int i = 0; i < static_cast<int>(currentSemesterCourses.size()); i++)
    {
        if(currentSemesterCourses[i].course == course)
        {
            currentSemesterCourses.erase(currentSemesterCourses.begin() + i);
            break;
        }
    }
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

double Student::getAverage() {
    double sum;
    for (StudentCourse studentCourse : passedCourses) {
        sum += studentCourse.grade;
    }
    return (sum / passedCourses.size());
}

unsigned Student::calculatePoints()
{
    unsigned points = 0;
    for(StudentCourse studentCourse : passedCourses)
    {
        Course* course = studentCourse.course;
        if(course)
        {
            points += course->getPoints();
        }
    }

    return points;
}

unsigned Student::getPassedMandatoryCount()
{
    unsigned count = 0;
    for(StudentCourse studentCourse : passedCourses)
    {
        Course* course = studentCourse.course;
        if(course)
        {
            if(course->getIsMandatory())
            {
                count++;
            }
            
        }
    }

    return count;
}