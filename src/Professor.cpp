#include "../include/Professor.h"
#include <iostream>
#include "../include/Course.h"

Professor::Professor(const std::string& startingName, unsigned startingAge) : 
Person(startingName, startingAge)
{

}

Professor::Professor(const std::string& startingName, unsigned startingAge, unsigned startingId) : 
Person(startingName, startingAge, startingId)
{

}

void Professor::printPerson() const 
{
    std::cout << "Professor ";
    Person::printPerson();
}

void Professor::printSemesterStats(bool isWinterSemester) const
{
    for(Course* course : courses)
    {
        if(isWinterSemester)
        {
            if(course->getSemester() % 2 != 0)
            {
                course->printStats();
            }
            else {
                std::cout << "No courses for this semester" << std::endl;
            }
        }
        else
        {
            if(course->getSemester() % 2 == 0)
            {
                course->printStats();
            }
            else {
                std::cout << "No courses for this semester" << std::endl;
            }
        }
    }
}

void Professor::addCourse(Course* courseToAdd)
{
    courses.push_back(courseToAdd);
}