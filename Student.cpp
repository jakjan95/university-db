#include "Student.hpp"

Student::Student(const std::string& name, const std::string& surname, Address address,
    size_t studentNumber, size_t pesel, Gender gender)
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
    out << student.name_ << ' ' << student.surname_ << ' ' << student.address_ << ' '
        << student.studentNumber_ << ' ' << student.pesel_ << ' '
        << Student::getStudentGenderAsString(student.gender_);
    return out;
}

std::istream& operator>>(std::istream& in, Student& student)
{
    std::cout << " *** Student data form ***\n";
    std::cout << "Enter name: ";
    std::cin >> student.name_;
    std::cout << "Enter surname: ";
    std::cin >> student.surname_;
    std::cout << "Enter addres\n:";
    std::cin >> student.address_;
    std::cout << "Enter student number: ";
    std::cin >> student.studentNumber_;
    std::cout << "Enter pesel: ";
    std::cin >> student.pesel_;
    std::cout << "Enter gender [M/F]: ";
    char gen;
    std::cin >> gen;
    student.gender_ = Student::getStudentGenderFromChar(gen);
    return in;
}
