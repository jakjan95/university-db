#pragma once

#include <vector>
#include <memory>
#include "gtest/gtest_prod.h"

#include "User.hpp"
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
        DeleteStudentRecord,
        PrintMenu,
        SaveDatabaseToFile,
        ReadDatabaseFromFile,
        ModifyEmpolyeeSalary,
        SortBySalary
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
    void deleteStudentRecord();
    void saveDatabaseToFile();
    Address createAddress();
    void readDatabaseFromFile();
    void modifyEmpolyeeSalary();
    void sortBySalary();


    bool isBirthdateValidForPesel(const std::string& pesel);
    bool isGenderValidForPesel(const std::string& pesel, Gender gender);
    bool isPeselCheckSumValid(const std::string& pesel);
    bool isGivenPeselValid(const std::string& pesel, Gender gender);
    FRIEND_TEST(DatabasePeselValidation, PeselsShouldBeValid);
    FRIEND_TEST(DatabasePeselValidation, PeselsShouldBeInvalid);

    std::vector<std::unique_ptr<User>> data_;
};
