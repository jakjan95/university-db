#pragma once

#include <iostream>
#include <string>

#include "Address.hpp"

class Student {
public:
    enum class Gender {
        male,
        female
    };

    Student() = default;
    Student(const std::string& name, const std::string& surname, Address address,
        size_t studentNumber, size_t pesel, Gender gender);

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    Address getAddress() const { return address_; }
    size_t getStudentNumber() const { return studentNumber_; }
    size_t getPesel() const { return pesel_; }
    Gender getStudentSex() const { return gender_; }

    static std::string getStudentGenderAsString(const Gender& gen)
    {
        switch (gen) {
        case Gender::female:
            return "Female";
        case Gender::male:
            return "Male";
        }
        return "Default";
    }

    static Gender getStudentGenderFromChar(char gender)
    {
        if (gender == 'F' || gender == 'f') {
            return Gender::female;
        }
        return Gender::male;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student);
    friend std::istream& operator>>(std::istream& in, Student& student);

private:
    std::string name_;
    std::string surname_;
    Address address_;
    size_t studentNumber_;
    size_t pesel_; // National Identity number in Poland
    Gender gender_;
};
