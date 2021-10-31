#pragma once

#include <vector>
#include "gtest/gtest_prod.h"

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
        SaveDatabaseToFile,
        ReadDatabaseFromFile
    };

    void run();

private:
    void performDatabaseOperation(Option operation);
    void printMenu();
    void quit();
    void addStudent();
    void printIndexRow();
    void displayDatabase();
    void addTestData();
    void searchBySurname();
    void searchByPesel();
    void sortByPesel();
    void sortBySurname();
    void deleteRecord();
    void saveDatabaseToFile();
    Address createAddress();
    void readDatabaseFromFile();

    bool isBirthdateValidForPesel(const std::string& pesel);
    bool isGenderValidForPesel(const std::string& pesel, Student::Gender  gender);
    bool isPeselCheckSumValid(const std::string& pesel);
    bool isGivenPeselValid(const std::string& pesel, Student::Gender gender);
    FRIEND_TEST(DatabasePeselValidation, PeselsShouldBeValid);
    FRIEND_TEST(DatabasePeselValidation, PeselsShouldBeInvalid);

    std::vector<Student> data_;
};
