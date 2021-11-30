#include <iomanip>
#include <sstream>
#include <string>

#include "Employee.hpp"

Employee::Employee(const std::string& name, const std::string& surname, Address address,
    const std::string& pesel, Gender gender, size_t salary)
    : User(name, surname, address, pesel, gender)
    , salary_ { salary }
{
}

void Employee::setSalary(size_t salary)
{
    salary_ = salary;
}

std::ostream& Employee::printInformations(std::ostream& out) const
{
    constexpr char delimeter = '|';
    out << std::setw(8) << '-' << delimeter << std::setw(8) << salary_ << delimeter;
    return out;
}
