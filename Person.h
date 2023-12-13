#pragma once

#include <string>
#include <iostream>

class Person
{
    private:
        static int count; // count how many people we have
        unsigned id; // unique id for each person
        std::string name;
        unsigned age;

    public:
        // getters
        unsigned getId() const {return id;};
        std::string getName() const {return name;};
        unsigned getAge() const {return age;};
        static int getCount() {return count; };

        // setters
        void setId(const unsigned newId) {id = newId;};
        void setName(const std::string newName) {name = newName;};
        void setAge(const unsigned newAge) {age = newAge;};

        // increase count manually
        static void increaseCount() {count++;};
        
        // copy constructor
        Person(const Person& other);
        Person();
        Person(const std::string& startingName, int startingAge);

        // deconstructor
        ~Person();

        // overload input and output operators
        friend std::istream& operator>>(std::istream& input, Person& person);

        friend std::ostream& operator<<(std::ostream& output, const Person& person);
};