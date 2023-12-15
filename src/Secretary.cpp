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

Secretary& Secretary::operator+=(Course& courseToAdd)
{
    addCourse(courseToAdd);
    return *this;
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

void Secretary::printCourses() const
{
    std::cout << "[Courses of " << name << "]" << std::endl;
    for (const auto& pair : courses) {
        std::cout << *(pair.second) << std::endl;
    }
}

void Secretary::addCourse(Course& courseToAdd)
{
    courses.insert(std::make_pair(courseToAdd.getIdCounter(), &courseToAdd));
}

void Secretary::removeCourse(const unsigned& courseId)
{
    courses.erase(courseId);
}

std::ostream& operator<<(std::ostream& os, const Secretary& s) {
    std::cout << "---Secretary " << s.name << "---" << std::endl;
    std::cout << "---Persons---" << std::endl;
    for (const auto& pair : s.persons) {
        std::cout << *(pair.second) << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Secretary& s) {
    Person* newPerson = new Person();
    std::cin >> *newPerson;
    s.persons.insert(std::make_pair(newPerson->getId(), newPerson));
    return is;
}

Person* Secretary::findPerson(const unsigned& id) {
    if (persons.find(id) != persons.end()) {
        return persons[id];
    } else {
        return nullptr;
    }
}

Secretary& Secretary::operator=(const Secretary& other) {
    name = other.name; 
    if (this != &other) {
        persons = other.persons;
    }
    return *this;
}
