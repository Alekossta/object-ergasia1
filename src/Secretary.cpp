#include "../include/Secretary.h"
#include <iostream>
#include "../include/Person.h"
#include "../include/Course.h"
#include <unordered_map>

Secretary::Secretary() : name("")
{

}

Secretary::Secretary(const std::string& startingName) : name(startingName)
{

}

Secretary::Secretary(const Secretary& other)
{
    name = other.name;
    for (const auto& pair : other.persons) {
        persons.insert(std::make_pair(pair.first, new Person(*(pair.second))));
    }
}

Secretary::~Secretary()
{
    for (const auto& pair : persons) {
        delete pair.second;
    }
}

Secretary& Secretary::operator+=(Person& personToAdd)
{
    return addPerson(personToAdd);
}

Secretary& Secretary::operator+(Person& personToAdd)
{
    return addPerson(personToAdd);
}

Secretary& Secretary::addPerson(Person& personToAdd)
{
    Person* newPerson = new Person(personToAdd);
    persons.insert(std::make_pair(personToAdd.getId(), newPerson));
    return *this;
}

// Course& Secretary::addCourse(Course& courseToAdd)
// {
//     // Course* newCourse = new Course(courseToAdd);
//     // const unsigned id = courses.size();
//     // courses.insert(std::make_pair(id, newCourse));
//     // return newCourse;
// }

std::ostream& operator<<(std::ostream& os, const Secretary& s) {
    std::cout << "---Secretary " << s.name << "---" << std::endl;
    std::cout << "---Persons---" << std::endl;
    for (const auto& pair : s.persons) {
        std::cout << *(pair.second) << std::endl;
    }
    std::cout << "---Courses---" << std::endl;
    // for (const auto& pair : s.courses)
    // {
    //     //std::cout << 
    // }
    std:: cout << "---------------";
    return os;
}

std::istream& operator>>(std::istream& is, Secretary& s) {
    Person* newPerson = new Person();
    std::cin >> *newPerson;
    s.persons.insert(std::make_pair(newPerson->getId(), newPerson));
    return is;
}

bool Secretary::findPerson(const unsigned& id) {
    return persons.find(id) != persons.end();
}

Secretary& Secretary::operator=(const Secretary& other) {
    name = other.name; 
    if (this != &other) {
        persons = other.persons;
    }
    return *this;
}