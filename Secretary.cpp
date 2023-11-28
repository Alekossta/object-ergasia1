#include "Secretary.h"
#include <iostream>
#include "Person.h"
#include <unordered_map>

Secretary::Secretary()
{

}

Secretary::Secretary(const Secretary& other)
{
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

std::ostream& operator<<(std::ostream& os, const Secretary& s) {
    std::cout << "People in the secretary: " << std::endl;
    for (const auto& pair : s.persons) {
        std::cout << *(pair.second) << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Secretary& s) {
    Person tempPerson;
    std::cin >> tempPerson;
    Person* newPerson = new Person(tempPerson.getName(), tempPerson.getAge());
    s.persons.insert(std::make_pair(newPerson->getId(), newPerson));
    return is;
}

bool Secretary::findPerson(const unsigned& id) {
    return persons.find(id) != persons.end();
}

Secretary& Secretary::operator=(const Secretary& other) {
    if (this != &other) {
        persons = other.persons;
    }
    return *this;
}
