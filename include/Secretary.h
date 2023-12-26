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
        unsigned pointsToGraduate;
        unsigned yearsOfStudy;
        bool isWinterSemester = true; // we start at default in winter semester
        unsigned year;

    public:
        // constructor(s)
        Secretary();
        Secretary(const std::string& secretaryName, unsigned secretaryPointsToGraduate,
         unsigned secretaryYearsOfStudy, unsigned secretaryYear);

        // copy constructor
        Secretary(const Secretary& other);

        // destructor
        ~Secretary();

        // getters
        std::unordered_map<unsigned, Person*>& getPersons() {return persons;};
        std::unordered_map<unsigned, Course*>& getCourses() {return courses;};
        std::string getName() const {return name;};
        unsigned getYear() const {return year;};
        unsigned getYearsOfStudy() const {return yearsOfStudy;};
        bool getIsWinterSemester() const {return isWinterSemester;};

        // setters
        void setYear(const unsigned& newYear) {year = newYear;};
        void setIsWinterSemester(const bool& newIsWinterSemester) {isWinterSemester = newIsWinterSemester;};

        // person functions

        void printProfessors() const;
        void printStudents() const;

        // student
        bool canGraduate(Student* student) const;

        // overload + operator

        Secretary& operator+=(Student& personToAdd);
        Secretary& operator+=(Professor& personToAdd);

        Secretary& addStudent(Student& studentToAdd);
        Secretary& addProfessor(Professor& professorToAdd);

        Secretary& operator+=(Course& courseToAdd);

        // course functions
        void printCourses() const;
        Secretary& addCourse(Course& courseToAdd);
        void removeCourse(const unsigned int& courseId);
        Course* getCourse(const unsigned int& courseId);

        unsigned calculateMandatoryCount() const;

        // overload input and output operators
        friend std::istream& operator>>(std::istream& input, Secretary& secretary);
        friend std::ostream& operator<<(std::ostream& output, const Secretary& secretary);

        // find person
        Person* findPerson(const unsigned& id);

        // overload assigment operator
        Secretary& operator=(const Secretary& other);

        // semester

        void switchSemester();

};