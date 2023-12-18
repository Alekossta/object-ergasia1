#pragma once

#include "Person.h"

#include <vector>

class Course;

struct StudentCourse
{
    Course* course;
    unsigned grade;
};

class Student : public Person
{
    public:
        // constructors
        Student(const std::string& startingName, int startingAge,
         unsigned studentEntryYear);

        // getters
        unsigned getEntryYear() const {return entryYear;};

        // setters
        void setEntryYear(unsigned newEntryYear) {entryYear = newEntryYear;};

        virtual void printPerson() const override;
        
    private:
        unsigned entryYear;
        std::vector<StudentCourse> currentSemesterCourses;
        std::vector<StudentCourse> allCourses;
};