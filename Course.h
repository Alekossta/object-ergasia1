#pragma once

class Course
{
    public:
        // constructors
        Course(unsigned coursePoints);
        Course(unsigned coursePoints, bool isCourseMandatory);

        // getters
        unsigned getPoints() const {return points;};
        bool getIsMandatory() const {return isMandatory;};

        // setters
        void setPoints(unsigned newPoints) {points = newPoints;};
        void setIsMandatory(bool newIsMandatory) {isMandatory = newIsMandatory;};

    private:
        unsigned points;
        bool isMandatory;
};