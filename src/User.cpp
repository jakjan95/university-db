#include <iomanip>
#include <sstream>
#include <string>

#include "User.hpp"

User::User(const std::string& name, const std::string& surname, Address address,
    const std::string& pesel, Gender gender)
    : name_ { name }
    , surname_ { surname }
    , address_ { address }
    , pesel_ { pesel }
    , gender_ { gender }
{
}

namespace GenderTools {
std::string getUserGenderAsString(const Gender& gen)
{
    switch (gen) {
    case Gender::female:
        return "Female";
    case Gender::male:
        return "Male";
    default:
        return "Undefined";
    }
}

Gender getUserGenderFromChar(char gender)
{
    if (gender == 'F' || gender == 'f') {
        return Gender::female;
    } else if (gender == 'M' || gender == 'm') {
        return Gender::male;
    }
    return Gender::undefined;
}

Gender getUserGenderFromString(const std::string& gender)
{
    if (gender == "Female" || gender == "female") {
        return Gender::female;
    } else if (gender == "Male" || gender == "male") {
        return Gender::male;
    }
    return Gender::undefined;
}
}
