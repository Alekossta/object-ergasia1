#include "../include/Person.h"
#include <iostream>
#include <string>

Person::Person() : id(count), name(""), age(0)
{
    count++;    
}

Person::Person(const std::string& startingName, int startingAge) : id(count), name(startingName), age(startingAge) {
    count++;
}

// copy constructor. do not increase count because this person already exists
Person::Person(const Person& other)
{
    setId(other.getId());
    setName(other.getName());
    setAge(other.getAge());
}

Person::~Person() {
    count--;
}

void Person::printPerson() const 
{
    std::cout << "[" << id << "] = Name: " << name << ", Age: " << age;
}

std::istream& operator>>(std::istream& input, Person& person) {
    std::cout << "---Creating new Person---" << std::endl;
    std::cout << "Enter name: ";
    input >> person.name;
    std::cout << "Enter age: ";
    input >> person.age;
    std::cout << "---Created new Person---" << std::endl << std::endl; // add one more endl to make it more clean
    return input;
}

std::ostream& operator<<(std::ostream& output, const Person& person) {
    person.printPerson();
    return output;
}