#pragma once

#include "Person.h"
#include <vector>

class Course;
class Professor : public Person
{
    private:
        std::vector<Course*> courses;

    public:
        Professor(const std::string& startingName, int startingAge);
        void addCourse(Course& courseToAdd);
        void removeCourse(Course& courseToRemove);
        std::vector<Course*>& getCourses() {return courses;};

        void printStats() const;

        virtual void printPerson() const override;
};