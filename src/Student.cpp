#include "../include/Student.h"

Student::Student(const std::string& startingName, int startingAge,
unsigned studentEntryYear) : Person(startingName, startingAge), entryYear(studentEntryYear)
{
    
}