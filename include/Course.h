#pragma once
#include <string>
#include <iostream>

class Course
{
    public:
        // constructors
        Course();
        Course(std::string courseName, unsigned coursePoints, bool courseIsMandatory,
        unsigned courseSemester, unsigned courseId);
        

        // getters
        unsigned getPoints() const {return points;};
        bool getIsMandatory() const {return isMandatory;};
        unsigned getSemester() const {return semester;};

        static int getIdCounter() {return idCounter;};

        // setters
        void setPoints(unsigned newPoints) {points = newPoints;};
        void setIsMandatory(bool newIsMandatory) {isMandatory = newIsMandatory;};
        void setSemester(unsigned newSemester) {semester = newSemester;};

        friend std::ostream& operator<<(std::ostream& output, const Course& course);

    private:
        static unsigned idCounter;
        std::string name;
        unsigned points;
        bool isMandatory;
        unsigned semester;
        unsigned id;

        
};