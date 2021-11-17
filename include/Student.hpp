#pragma once

#include "User.hpp"

class Student : public User {
public:
    Student() = default;
    Student(const std::string& name, const std::string& surname, Address address,
        size_t studentNumber, const std::string& pesel, Gender gender);
    size_t getStudentNumber() const { return studentNumber_; }
    
private:
    std::ostream& printInformations(std::ostream& out) const override;
    size_t studentNumber_;
};
