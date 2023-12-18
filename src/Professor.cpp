#include "../include/Professor.h"
#include <iostream>
#include "../include/Course.h"

Professor::Professor(const std::string& startingName, int startingAge) : 
Person(startingName, startingAge)
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
                std::cout << *course;
            }
        }
        else
        {
            if(course->getSemester() % 2 == 0)
            {
                std::cout << *course;
            }
        }
    }
}

void Professor::addCourse(Course* courseToAdd)
{
    courses.push_back(courseToAdd);
}