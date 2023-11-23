#pragma once

#include <string>
#include <iostream>

class Person
{
    public:

        static int count; // count how many people we have
        std::string name;
        unsigned age;
        // constructors
        Person();
        Person(const std::string& startingName);
        Person(int startingAge);
        Person(int startingAge, const std::string& startingName);
        
        // deconstructors
        ~Person();

        static int getCount() {return count; };

        friend std::istream& operator>>(std::istream& input, Person& person);

        friend std::ostream& operator<<(std::ostream& output, const Person& person);

};