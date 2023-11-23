#include "Person.h"
#include <iostream>
#include <string>

Person::Person(): name(""), age(0) {
    count++;
}

Person::Person(const std::string& startingName): name(startingName), age(0) {
    count++;
}

Person::Person(int startingAge): name(""), age(startingAge) {
    count++;
}

Person::Person(int startingAge, const std::string& startingName) : name(startingName), age(startingAge)
{
    count++;
}

Person::~Person() {
    count--;
}

std::istream& operator>>(std::istream& input, Person& person) {
    std::cout << "Enter name: ";
    input >> person.name;
    std::cout << "Enter age: ";
    input >> person.age;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Person& person) {
    output << "Name: " << person.name << ", Age: " << person.age;
    return output;
}