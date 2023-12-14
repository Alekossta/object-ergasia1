#include "../include/Professor.h"

Professor::Professor(const std::string& startingName, int startingAge) : 
Person(startingName, startingAge)
{
}

void Professor::addCourse(Course& courseToAdd)
{
    courses.push_back(&courseToAdd);
}