#pragma once

#include <vector>

#include "Student.hpp"
class Database {
public:
    enum class Option {
        Quit,
        AddStudent,
        DisplayDatabase,
        SearchBySurname,
        SearchByPesel,
        SortByPesel,
        SortBySurname,
        DeleteRecord,
        PrintMenu,
    };

    void run();

private:
    void performDatabaseOperation(Option operation);
    void printMenu();
    void quit();
    void addStudent();

    std::vector<Student> data_;
};