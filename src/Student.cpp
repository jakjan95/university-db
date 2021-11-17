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
    out << std::setw(8) << studentNumber_ << delimeter << std::setw(8) << '-' << delimeter;
    return out;
}
