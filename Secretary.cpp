#include "Secretary.h"
#include <iostream>
#include "Person.h"
#include <unordered_map>

Secretary::Secretary()
{

}

Secretary::Secretary(const Secretary& other) : persons(other.persons)
{

}

Secretary::~Secretary()
{

}

Secretary& Secretary::operator+(Person& personToAdd)
{
    persons.insert(std::make_pair(personToAdd.name, &personToAdd));
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Secretary& s) {
    for (const auto& pair : s.persons) {
        os << "Person Name: " << pair.first << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Secretary& s) {
    std::string name;
    std::cout << "Enter person's name: ";
    is >> name;
    Person p{name}; // Assuming Person has a constructor accepting a name
    s + p;
    return is;
}

// bool Secretary::findPerson(const std::string& name) {
//     return persons.find(name) != persons.end();
// }

Secretary& Secretary::operator=(const Secretary& other) {
    if (this != &other) {
        persons = other.persons;
    }
    return *this;
}
