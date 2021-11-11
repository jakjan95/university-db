#include <iomanip>
#include <sstream>
#include <string>

#include "Student.hpp"

Student::Student(const std::string& name, const std::string& surname, Address address,
    size_t studentNumber, const std::string& pesel, Gender gender)
    : User(name, surname, address, pesel, gender)
    , studentNumber_ { studentNumber }
{
}

std::ostream& Student::printInformations(std::ostream& out) const
{
    constexpr char delimeter = '|';
    out << delimeter << std::setw(14) << name_ << delimeter << std::setw(14)
        << surname_ << delimeter << std::setw(60) << address_ << delimeter << std::setw(8)
        << studentNumber_ << delimeter << std::setw(14) << pesel_ << delimeter << std::setw(8)
        << GenderTools::getUserGenderAsString(gender_) << delimeter;
    return out;
}

std::istream& operator>>(std::istream& in, Student& student)
{
    char tmp;
    in >> tmp;

    in >> std::ws;
    std::getline(in, student.name_, '|');

    in >> std::ws;
    std::getline(in, student.surname_, '|');

    in >> std::ws;
    std::string studentAddressString;
    std::getline(in, studentAddressString, '|');

    std::stringstream ssAddress { studentAddressString };
    ssAddress >> student.address_;

    in >> student.studentNumber_;
    in >> tmp;

    std::getline(in, student.pesel_, '|');

    std::string gender;
    in >> std::ws;
    std::getline(in, gender, '|');

    student.gender_ = GenderTools::getUserGenderFromString(gender);
    return in;
}
