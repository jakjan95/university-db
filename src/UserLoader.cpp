#include "UserLoader.hpp"
#include "Student.hpp"

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

    if (in.peek() == '-') {
        // TODO Employee handling
    } else {
        size_t studentNumber;
        in >> studentNumber;
        in >> tmp;
        in >> tmp;
        in >> tmp;
        userLoader.user.reset(dynamic_cast<User*>(new Student(name, surname, adr, studentNumber, pesel, gen)));
    }
    return in;
}
