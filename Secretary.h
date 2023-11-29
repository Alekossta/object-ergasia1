#pragma once
#include <iostream>
#include <unordered_map>

class Person;

class Secretary 
{
    private:
        // map that stores id and pointer to person
        std::unordered_map<unsigned, Person*> persons;
    public:
        // constructor(s)
        Secretary();

        // copy constructor
        Secretary(const Secretary& other);

        // destructor
        ~Secretary();

        // getters
        std::unordered_map<unsigned, Person*>& getPersons() {return persons;};

        // overload + operator
        Secretary& operator+=(Person& personToAdd);
        Secretary& operator+(Person& personToAdd);

        Secretary& addPerson(Person& personToAdd);

        // overload input and output operators
        friend std::istream& operator>>(std::istream& input, Secretary& secretary);
        friend std::ostream& operator<<(std::ostream& output, const Secretary& secretary);

        // find person
        bool findPerson(const unsigned& id);

        // overload assigment operator
        Secretary& operator=(const Secretary& other);
};