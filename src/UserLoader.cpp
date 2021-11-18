#include <algorithm>
#include <string>

#include "Employee.hpp"
#include "Student.hpp"
#include "UserLoader.hpp"

std::istream& operator>>(std::istream& in, UserLoader& userLoader)
{
    char tmp {};
    in >> tmp;

    in >> std::ws;
    std::string name;
    std::getline(in, name, '|');

    in >> std::ws;
    std::string surname;
    std::getline(in, surname, '|');

    in >> std::ws;
    std::string userAddressString;
    std::getline(in, userAddressString, '|');

    std::stringstream ssAddress { userAddressString };
    Address adr;
    ssAddress >> adr;

    std::string pesel;
    std::getline(in, pesel, '|');

    std::string gender;
    in >> std::ws;
    std::getline(in, gender, '|');
    Gender gen;
    gen = GenderTools::getUserGenderFromString(gender);

    std::string studentNumberOrHypen;
    std::getline(in, studentNumberOrHypen, '|');
    studentNumberOrHypen.erase(
        std::remove(studentNumberOrHypen.begin(), studentNumberOrHypen.end(), ' '),
        studentNumberOrHypen.end());

    if (studentNumberOrHypen == std::string("-")) {
        size_t salary;
        in >> salary;
        in >> tmp;
        userLoader.user.reset(dynamic_cast<User*>(new Employee(name, surname, adr, pesel, gen, salary)));
    } else {
        size_t studentNumber = std::stoi(studentNumberOrHypen);
        in >> tmp;
        in >> tmp;
        userLoader.user.reset(dynamic_cast<User*>(new Student(name, surname, adr, studentNumber, pesel, gen)));
    }
    return in;
}
