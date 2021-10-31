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

    std::vector<Student> data_;
};