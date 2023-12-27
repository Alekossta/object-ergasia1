#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "../include/Professor.h"
#include "../include/Student.h"

class Course
{
    public:
        // constructors
        Course();
        Course(std::string courseName, unsigned coursePoints, bool courseIsMandatory,
        unsigned courseSemester);
        Course(std::string courseName, unsigned coursePoints, bool courseIsMandatory,
        unsigned courseSemester, unsigned courseId);

        // getters
        std::string getName() const {return name;};
        unsigned getPoints() const {return points;};
        bool getIsMandatory() const {return isMandatory;};
        unsigned getSemester() const {return semester;};
        unsigned getId() const {return id;};    
        static int getIdCounter() {return idCounter;};
        std::vector<Student*>& getStudents() {return students;};

        // setters
        void setPoints(unsigned newPoints) {points = newPoints;};
        void setIsMandatory(bool newIsMandatory) {isMandatory = newIsMandatory;};
        void setSemester(unsigned newSemester) {semester = newSemester;};

        // manage professors
        void addProfessor(Professor* newProfessor);
        bool hasProfessors();

        // manage students
        void addStudent(Student* newStudent);

        // print functions
        void printProfessors();
        void printStats();
        void printStudents(); // mainly for debugging

        friend std::ostream& operator<<(std::ostream& output, const Course& course);

    private:
        static unsigned idCounter;
        std::string name;
        unsigned points;
        bool isMandatory;
        unsigned semester;
        unsigned id;
        std::vector<Professor*> professors;
        std::vector<Student*> students;
};