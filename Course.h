#pragma once

#include <string>

class Course
{
    public:
        // constructors
        Course();
        Course(std::string courseName, unsigned coursePoints, bool courseIsMandatory,
        unsigned courseSemester);
        

        // getters
        unsigned getPoints() const {return points;};
        bool getIsMandatory() const {return isMandatory;};
        unsigned getSemester() const {return semester;};

        // setters
        void setPoints(unsigned newPoints) {points = newPoints;};
        void setIsMandatory(bool newIsMandatory) {isMandatory = newIsMandatory;};
        void setSemester(unsigned newSemester) {semester = newSemester;};

    private:
        std::string name;
        unsigned points;
        bool isMandatory;
        unsigned semester;
};