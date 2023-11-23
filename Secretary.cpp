#include "Secretary.h"
#include <iostream>
#include "Person.h"
#include <unordered_map>

Secretary::Secretary()
{

}

Secretary::Secretary(const Secretary& other)
{

}

Secretary::~Secretary()
{

}

Secretary& operator+(Person& personToAdd)
{
   persons[personToAdd.name] = new Person(personToAdd.age, personToAdd.name);
   return *this;
}

friend std::ostream& operator<<(std::ostream& os, const Secretary& s) {

}

friend std::istream& operator>>(std::istream& is, Secretary& s) {
  
}

bool findPerson(const std::string& name) {

}

Secretary& Secretary::operator=(const Secretary& other)
{

}