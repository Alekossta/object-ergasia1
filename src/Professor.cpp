#include "../include/Professor.h"
#include <iostream>

Professor::Professor(const std::string& startingName, int startingAge) : 
Person(startingName, startingAge)
{

}

void Professor::printPerson() const 
{
    std::cout << "Professor ";
    Person::printPerson();
}

void Professor::addCourse(Course& courseToAdd)
{
    courses.push_back(&courseToAdd);
}