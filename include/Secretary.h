#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class Person;
class Course;

class Secretary 
{
    private:
        std::unordered_map<unsigned, Person*> persons;
        std::unordered_map<unsigned, Course*> courses;

        // name of university
        std::string name;

    public:
        // constructor(s)
        Secretary();
        Secretary(const std::string& startingName);

        // copy constructor
        Secretary(const Secretary& other);

        // destructor
        ~Secretary();

        // getters
        std::unordered_map<unsigned, Person*>& getPersons() {return persons;};
        std::string getName() const {return name;};

        // overload + operator
        Secretary& operator+=(Person& personToAdd);
        Secretary& operator+(Person& personToAdd);

        Secretary& addPerson(Person& personToAdd);

        Secretary& operator+=(Course& courseToAdd);

        // course functions
        void printCourses() const;
        void addCourse(Course& courseToAdd);
        void removeCourse(const unsigned& courseId);
        Course* getCourse(const unsigned& courseId);

        // overload input and output operators
        friend std::istream& operator>>(std::istream& input, Secretary& secretary);
        friend std::ostream& operator<<(std::ostream& output, const Secretary& secretary);

        // find person
        Person* findPerson(const unsigned& id);

        // overload assigment operator
        Secretary& operator=(const Secretary& other);
};