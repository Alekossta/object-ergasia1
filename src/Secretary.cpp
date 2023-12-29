#include "../include/Secretary.h"
#include <iostream>
#include <unordered_map>

/// class functions ///

Secretary::Secretary() : name("")
{

}

Secretary::Secretary(const std::string& secretaryName, unsigned secretaryPointsToGraduate,
unsigned secretaryYearsOfStudy, unsigned secretaryYear) : 
name(secretaryName), pointsToGraduate(secretaryPointsToGraduate), yearsOfStudy(secretaryYearsOfStudy),
year(secretaryYear)
{

}

Secretary::Secretary(const Secretary& other)
{
    name = other.name;
    for (const auto& pair : other.persons) {
        persons.insert(std::make_pair(pair.first, new Person(*(pair.second))));
    }
}

Secretary::~Secretary()
{
    for (const auto& pair : persons) {
        delete pair.second;
    }

    for (const auto& pair : courses) {
        delete pair.second;
    }
}

/// persons functions ///
void Secretary::printProfessors() const 
{
    std::cout << std::endl << "[Professors of " << this->getName() << "]" << std::endl;
    for (const auto& pair : persons) {
        Professor* professor = dynamic_cast<Professor*>(pair.second);
        if(professor != nullptr)
        {
            std::cout << "> " << *professor << std::endl;
        }
    }
    std::cout << std::endl;
}

void Secretary::printStudents() const
{
    std::cout << std::endl << "[Students of " << this->getName() << "]" << std::endl;
    for (const auto& pair : persons) {
        Student* student = dynamic_cast<Student*>(pair.second);
        if(student != nullptr)
        {
            std::cout << "> " << *student << std::endl;
        }
    }
    std::cout << std::endl;
}

bool Secretary::canGraduate(Student* student) const
{
    if(student == nullptr) return false;
    
    bool hasPoints = student->calculatePoints() >= pointsToGraduate;

    bool hasMandatory = student->getPassedMandatoryCount() == calculateMandatoryCount();

    bool hasCompletedYearsOfStudy = (year - student->getEntryYear()) >= yearsOfStudy;

    return hasPoints && hasMandatory && hasCompletedYearsOfStudy;
}


/// adding new persons (students and professors) ///

Secretary& Secretary::operator+=(Student& studentToAdd)
{
    return addStudent(studentToAdd);
}

Secretary& Secretary::operator+=(Professor& professorToAdd)
{
    return addProfessor(professorToAdd);
}

Secretary& Secretary::addStudent(Student& studentToAdd)
{
    Student* newPerson = new Student(studentToAdd);
    persons.insert(std::make_pair(studentToAdd.getId(), newPerson));
    return *this;
}

Secretary& Secretary::addProfessor(Professor& professorToAdd)
{
    Professor* newPerson = new Professor(professorToAdd);
    persons.insert(std::make_pair(professorToAdd.getId(), newPerson));
    return *this;
}

/// Courses code ///

void Secretary::printCourses() const
{
    if (isWinterSemester) {
        std::cout << std::endl << "[Winter Courses of " << name << "]" << std::endl;
        for (const auto& pair : courses) {
            if (pair.second->getSemester() % 2 != 0) {

                std::cout << "> " << *(pair.second) << std::endl;
            }
        }
    } else {
        std::cout << std::endl << "[Summer Courses of " << name << "]" << std::endl;
        for (const auto& pair : courses) {
            if (pair.second->getSemester() % 2 == 0) {

                std::cout << "> " << *(pair.second) << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

Secretary& Secretary::operator+=(Course& courseToAdd)
{
    return addCourse(courseToAdd);
}

Secretary& Secretary::addCourse(Course& courseToAdd)
{
    Course* newCourse = new Course(courseToAdd);
    courses.insert(std::make_pair(courseToAdd.getId(), newCourse));
    return *this;
}

void Secretary::removeCourse(const unsigned int& courseId)
{
    for (const auto& pair : courses) {
        if (pair.second->getId() == courseId) {
            delete pair.second;
            courses.erase(courseId);
            break;
        }
    }
}

Course* Secretary::getAvailableCourse(const unsigned int& courseId)
{
    if (isWinterSemester) {
        for (const auto& pair : courses) {
            if (pair.second->getSemester() % 2 != 0 && pair.second->getId() == courseId) {
                return pair.second;
            }
        }
    } else {
        for (const auto& pair : courses) {
            if (pair.second->getSemester() % 2 == 0 && pair.second->getId() == courseId) {
                return pair.second;
            }
        }
    }
    return nullptr;
}

Course* Secretary::getCourse(const unsigned int& courseId)
{
    for (const auto& pair : courses) {
        if (pair.second->getId() == courseId) {
            return pair.second;
        }
    }
    return nullptr;
}

unsigned Secretary::calculateMandatoryCount() const
{
    unsigned count = 0;
    for(auto pair : courses)
    {
        Course* course = pair.second;
        if(course)
        {
            if(course->getIsMandatory())
            {
                count++;
            }
        }
    }

    return count;
}

/// input and output operators ///

std::ostream& operator<<(std::ostream& os, const Secretary& s) {
    std::cout << "---Secretary " << s.name << "---" << std::endl;
    std::cout << "---Persons---" << std::endl;
    for (const auto& pair : s.persons) {
        std::cout << *(pair.second) << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Secretary& s) {
    Person* newPerson = new Person();
    std::cin >> *newPerson;
    s.persons.insert(std::make_pair(newPerson->getId(), newPerson));
    return is;
}

Person* Secretary::findPerson(const unsigned& id) {
    if (persons.find(id) != persons.end()) {
        return persons[id];
    } else {
        return nullptr;
    }
}

Secretary& Secretary::operator=(const Secretary& other) {
    name = other.name; 
    if (this != &other) {
        persons = other.persons;
    }
    return *this;
}

void Secretary::switchSemester() {
    if (isWinterSemester) year++;
    isWinterSemester = !isWinterSemester; // switch to other semester

    // clear all courses from students
    for (const auto& pair : persons) {
        Student* student = dynamic_cast<Student*>(pair.second);
        if (student != nullptr) {
            student->getCurrentSemesterCourses().clear();
        }
    }

    // clear all courses from professors
    for (const auto& pair : persons) {
        Professor* professor = dynamic_cast<Professor*>(pair.second);
        // loop through all course of professor
        if (professor != nullptr) {
            for (const auto& pair2 : professor->getCourses()) {
                Course* course = pair2;
                if (course != nullptr) {
                    course->getProfessors().clear();
                    professor->getCourses().clear();
                }
            }
        }
    }
}
