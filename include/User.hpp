#pragma once

#include <iostream>
#include <string>

#include "Address.hpp"

class User {
public:
    enum class Gender {
        male,
        female
    };

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

    static std::string getUserGenderAsString(const Gender& gen)
    {
        switch (gen) {
        case Gender::female:
            return "Female";
        case Gender::male:
            return "Male";
        }
        return "Default";
    }

    static Gender getUserGenderFromChar(char gender)
    {
        if (gender == 'F' || gender == 'f') {
            return Gender::female;
        }
        return Gender::male;
    }

    static Gender getUserGenderFromString(const std::string& gender)
    {
        if (gender == "Female" || gender == "female") {
            return Gender::female;
        }
        return Gender::male;
    }

protected:
    std::string name_;
    std::string surname_;
    Address address_;
    std::string pesel_; // National Identity number in Poland
    Gender gender_;
};
