#pragma once

#include <string>
#include <iostream>

class Person
{
    public:

        static int count; // count how many people we have
        unsigned id;
        std::string name;
        unsigned age;

        // constructors
        Person();
        Person(const std::string& startingName);
        Person(const std::string& startingName, int startingAge);

        // deconstructor
        ~Person();

        static int getCount() {return count; };

        friend std::istream& operator>>(std::istream& input, Person& person);

        friend std::ostream& operator<<(std::ostream& output, const Person& person);

};