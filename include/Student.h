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
        unsigned getPoints() const {return points;};
        unsigned getMandatoryCoursesPassed() const {return mandatoryCoursesPassed;};

        // setters
        void setEntryYear(unsigned newEntryYear) {entryYear = newEntryYear;};

        virtual void printPerson() const override;

        // course handlers

        void printCurrentSemesterGrades();
        void printAllGrades();
        
        void addCourse(Course* newCourse);
        
    private:
        unsigned entryYear;
        unsigned points;
        unsigned mandatoryCoursesPassed;
        std::vector<StudentCourse> currentSemesterCourses;
        std::vector<StudentCourse> allCourses;
};