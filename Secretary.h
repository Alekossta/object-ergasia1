#pragma once
#include <iostream>
#include <unordered_map>

class Person;

class Secretary 
{
    public:

        std::unordered_map<std::string, Person*> persons; 

        // constructor(s)
        Secretary();

        // copy constructor
        Secretary(const Secretary& other);

        // destructor
        ~Secretary();

        // overload + operator
        Secretary operator+(const Person& personToAdd);

        // overload input and output operators
        friend std::istream& operator>>(std::istream& input, Secretary& secretary);
        friend std::ostream& operator<<(std::ostream& output, const Secretary& secretary);

        // find person
        bool findPerson(const Person& personToFind);

        // overload assigment operator
        Secretary& operator=(const Secretary& other);
};