#include "Person.h"
#include <iostream>
#include <string>

Person::Person() {
    count++;
    id = count;
    name = "";
    age = 0;
}

Person::Person(const std::string& startingName) {
    count++;
    id = count;
    name = startingName;
    age = 0;
}

Person::Person(const std::string& startingName, int startingAge) {
    count++;
    id = count;
    name = startingName;
    age = startingAge;
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
    output << "[id: " << person.id << "] Name: " << person.name << ", Age: " << person.age;
    return output;
}