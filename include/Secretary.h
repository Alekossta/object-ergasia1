#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "../include/Person.h"
#include "../include/Student.h"
#include "../include/Professor.h"
#include "../include/Course.h"

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
        std::unordered_map<unsigned, Course*>& getCourses() {return courses;};
        std::string getName() const {return name;};

        // person functions

        void printProfessors() const;
        void printStudents() const;

        // overload + operator

        Secretary& operator+=(Student& personToAdd);
        Secretary& operator+=(Professor& personToAdd);

        Secretary& addStudent(Student& studentToAdd);
        Secretary& addProfessor(Professor& professorToAdd);

        Secretary& operator+=(Course& courseToAdd);

        // course functions
        void printCourses(bool isWinterSemester) const;
        Secretary& addCourse(Course& courseToAdd);
        void removeCourse(const unsigned int& courseId);
        Course* getCourse(const unsigned int& courseId, bool isWinterSemester);
        Course* getCourse(const unsigned int& courseId);

        // overload input and output operators
        friend std::istream& operator>>(std::istream& input, Secretary& secretary);
        friend std::ostream& operator<<(std::ostream& output, const Secretary& secretary);

        // find person
        Person* findPerson(const unsigned& id);

        // overload assigment operator
        Secretary& operator=(const Secretary& other);
};