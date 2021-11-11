#pragma once

#include <iostream>
#include <string>

#include "Address.hpp"

enum class Gender {
    male,
    female,
    undefined
};

namespace GenderTools {
std::string getUserGenderAsString(const Gender& gen);
Gender getUserGenderFromChar(char gender);
Gender getUserGenderFromString(const std::string& gender);
}
class User {
public:
    virtual ~User() = default;
    User() = default;
    User(const std::string& name, const std::string& surname, Address address, const std::string& pesel, Gender gender);

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    Address getAddress() const { return address_; }
    std::string getPesel() const { return pesel_; }
    Gender getUserGender() const { return gender_; }
    virtual std::ostream& printInformations(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const User& user)
    {
        return user.printInformations(out);
    }

protected:
    std::string name_;
    std::string surname_;
    Address address_;
    std::string pesel_; // National Identity number in Poland
    Gender gender_;
};
