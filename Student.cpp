#include <iomanip>
#include <sstream>
#include <string>

#include "Student.hpp"

Student::Student(const std::string& name, const std::string& surname, Address address,
    size_t studentNumber, const std::string& pesel, Gender gender)
    : name_ { name }
    , surname_ { surname }
    , address_ { address }
    , studentNumber_ { studentNumber }
    , pesel_ { pesel }
    , gender_ { gender }
{
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
    constexpr char delimeter = '|';
    out << delimeter << std::setw(14) << student.name_ << delimeter << std::setw(14)
        << student.surname_ << delimeter << std::setw(60) << student.address_ << delimeter << std::setw(8)
        << student.studentNumber_ << delimeter << std::setw(14) << student.pesel_ << delimeter << std::setw(8)
        << Student::getStudentGenderAsString(student.gender_) << delimeter;
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

    student.gender_ = Student::getStudentGenderFromString(gender);
    return in;
}
