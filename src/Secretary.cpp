#include "../include/Secretary.h"
#include <iostream>
#include <unordered_map>

/// class functions ///

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

    for (const auto& pair : courses) {
        delete pair.second;
    }
}

/// persons functions ///
void Secretary::printProfessors() const 
{
    for (const auto& pair : persons) {
        Professor* professor = dynamic_cast<Professor*>(pair.second);
        if(professor != nullptr)
        {
            std::cout << *professor << std::endl;
        }
    }    
}

void Secretary::printStudents() const
{
    for (const auto& pair : persons) {
        Student* student = dynamic_cast<Student*>(pair.second);
        if(student != nullptr)
        {
            std::cout << *student << std::endl;
        }
    }     
}


/// adding new persons (students and professors) ///

Secretary& Secretary::operator+=(Student& studentToAdd)
{
    return addStudent(studentToAdd);
}

Secretary& Secretary::operator+=(Professor& professorToAdd)
{
    return addProfessor(professorToAdd);
}

Secretary& Secretary::addStudent(Student& studentToAdd)
{
    Student* newPerson = new Student(studentToAdd);
    persons.insert(std::make_pair(studentToAdd.getId(), newPerson));
    return *this;
}

Secretary& Secretary::addProfessor(Professor& professorToAdd)
{
    Professor* newPerson = new Professor(professorToAdd);
    persons.insert(std::make_pair(professorToAdd.getId(), newPerson));
    return *this;
}

/// Courses code ///

void Secretary::printCourses() const
{
    std::cout << "[Courses of " << name << "]" << std::endl;
    for (const auto& pair : courses) {
        std::cout << *(pair.second) << std::endl;
    }
}

Secretary& Secretary::operator+=(Course& courseToAdd)
{
    return addCourse(courseToAdd);
}

Secretary& Secretary::addCourse(Course& courseToAdd)
{
    Course* newCourse = new Course(courseToAdd);
    courses.insert(std::make_pair(courseToAdd.getId(), newCourse));
    return *this;
}

void Secretary::removeCourse(const unsigned int& courseId)
{
    for (const auto& pair : courses) {
        if (pair.second->getId() == courseId) {
            delete pair.second;
            courses.erase(courseId);
            break;
        }
    }
}

Course* Secretary::getCourse(const unsigned int& courseId)
{
    for (const auto& pair : courses) {
        if (pair.second->getId() == courseId) {
            return pair.second;
        }
    }
    return nullptr;
}

/// input and output operators ///

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
