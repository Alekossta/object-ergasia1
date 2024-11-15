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
        Student(const std::string& startingName, unsigned startingAge,
         unsigned studentEntryYear);
        Student(const std::string& startingName, unsigned startingAge,
         unsigned studentEntryYear, unsigned startingId);

        // getters
        unsigned getEntryYear() const {return entryYear;};
        std::vector<StudentCourse>& getCurrentSemesterCourses() {return currentSemesterCourses;};
        std::vector<StudentCourse>& getPassedCourses() {return passedCourses;};

        // setters
        void setEntryYear(unsigned newEntryYear) {entryYear = newEntryYear;};

        virtual void printPerson() const override;

        void setGrade(Course* course, unsigned grade);

        // course handlers

        void printCurrentSemesterGrades();
        void printPassedGrades();
        
        void addCourse(Course* newCourse);
        void addPassedCourse(Course* newCourse, unsigned grade);
        void removeCourse(Course* course);

        unsigned getGradeForCourse(Course* course);
        bool hasPassedCourse(Course* course);
        bool hasEnrolledCourse(Course* course);
        double getAverage();

        unsigned calculatePoints();
        unsigned getPassedMandatoryCount();
        
    private:
        unsigned entryYear;
        std::vector<StudentCourse> currentSemesterCourses;
        std::vector<StudentCourse> passedCourses;
};