#pragma once

#include "User.hpp"

class Student : public User {
public:
    Student() = default;
    Student(const std::string& name, const std::string& surname, Address address,
        size_t studentNumber, const std::string& pesel, User::Gender gender);
    size_t getStudentNumber() const { return studentNumber_; }
    std::ostream& printInformations(std::ostream& out) const override;

    friend std::istream& operator>>(std::istream& in, Student& student);

private:
    size_t studentNumber_;
};
