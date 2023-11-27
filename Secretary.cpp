#include "Secretary.h"
#include <iostream>
#include "Person.h"
#include <unordered_map>
#include <memory>

Secretary::Secretary()
{

}

Secretary::Secretary(const Secretary& other)
{
    for (const auto& pair : other.persons) {
        persons.insert(std::make_pair(pair.first, pair.second));
    }
}

Secretary::~Secretary()
{

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
    persons.insert(std::make_pair(personToAdd.getId(), &personToAdd));
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
    std::shared_ptr<Person> p = std::make_shared<Person>();
    Person::increaseCount(); // increase count manually because make_shared cannot call the constructor (it's private)
    std::cin >> *p;
    s += *p;
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
