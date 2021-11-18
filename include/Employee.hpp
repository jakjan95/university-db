#pragma once

#include "User.hpp"

class Employee : public User {
public:
    Employee() = default;
    Employee(const std::string& name, const std::string& surname, Address address,
        const std::string& pesel, Gender gender, size_t salary);
    size_t getSalary() const { return salary_; }

private:
    std::ostream& printInformations(std::ostream& out) const override;
    size_t salary_;
};
