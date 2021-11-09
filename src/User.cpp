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
