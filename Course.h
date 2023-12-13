#pragma once

class Course
{
    public:
        // constructors
        Course();
        Course(unsigned coursePoints);
        Course(unsigned coursePoints, bool isCourseMandatory);
        Course(unsigned coursePoints, bool isCourseMandatory, unsigned courseSemester);

        // getters
        unsigned getPoints() const {return points;};
        bool getIsMandatory() const {return isMandatory;};
        unsigned getSemester() const {return semester;};

        // setters
        void setPoints(unsigned newPoints) {points = newPoints;};
        void setIsMandatory(bool newIsMandatory) {isMandatory = newIsMandatory;};
        void setSemester(unsigned newSemester) {semester = newSemester;};

    private:
        unsigned points;
        bool isMandatory;
        unsigned semester;
};