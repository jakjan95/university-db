#pragma once

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
};
