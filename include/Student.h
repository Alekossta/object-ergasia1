#pragma once

#include "Person.h"

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
};