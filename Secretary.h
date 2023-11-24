#pragma once
#include <iostream>
#include <unordered_map>

class Person;

class Secretary 
{
    public:
        // map that stores id and pointer to person
        std::unordered_map<unsigned, Person*> persons;

        // constructor(s)
        Secretary();

        // copy constructor
        Secretary(const Secretary& other);

        // destructor
        ~Secretary();

        // overload + operator
        Secretary& operator+(Person& personToAdd);


        // overload input and output operators
        friend std::istream& operator>>(std::istream& input, Secretary& secretary);
        friend std::ostream& operator<<(std::ostream& output, const Secretary& secretary);

        // find person
        bool findPerson(const unsigned& id);

        // overload assigment operator
        Secretary& operator=(const Secretary& other);
};