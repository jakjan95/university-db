#include <algorithm>
#include <iostream>

#include "Database.hpp"

void Database::run()
{
    std::cout << "**** University Database software v0.0.1 ****\n";
    printMenu();
    std::cout << "********************************************* \n";
    while (true) {
        std::cout << "ENTER OPTION: ";
        size_t option;
        std::cin >> option;
        performDatabaseOperation(static_cast<Option>(option));
    }
}

void Database::performDatabaseOperation(Option operation)
{
    switch (operation) {
    case Option::AddStudent:
        addStudent();
        break;
    case Option::DisplayDatabase:
        std::cout << "  DISPLAY DATABASE\n";
        break;
    case Option::SearchBySurname:
        std::cout << " SEARCH BY SURNAME\n";
        break;
    case Option::SearchByPesel:
        std::cout << " SEARCH BY PESEL\n";
        break;
    case Option::SortByPesel:
        std::cout << " SORT BY PESEL\n";
        break;
    case Option::SortBySurname:
        std::cout << " SORT BY SURNAME\n";
        break;
    case Option::DeleteRecord:
        std::cout << " DELETE RECORD\n";
        break;
    case Option::PrintMenu:
        printMenu();
        break;
    case Option::Quit:
        quit();
        break;
    default:
        std::cout << " WRONG OPTION\n";
        break;
    }
}

void Database::printMenu()
{
    std::cout << "=============================================\n";
    std::cout << "              > MENU  <\n";
    std::cout << "  1   ADD NEW STUDENT\n";
    std::cout << "  2   DISPLAY DATABASE\n";
    std::cout << "  3   SEARCH BY SURNAME\n";
    std::cout << "  4   SEARCH BY PESEL\n";
    std::cout << "  5   SORT BY PESEL\n";
    std::cout << "  6   SORT BY SURNAME\n";
    std::cout << "  7   DELETE RECORD\n";
    std::cout << "  8   PRINT MENU\n";
    std::cout << "  0   QUIT\n";
    std::cout << "=============================================\n";
}

void Database::quit()
{
    std::cout << " QUITTING THE PROGRAM....... \n";
    std::exit(0);
}

void Database::addStudent()
{
    Student tmp;
    std::cin >> tmp;
    data_.emplace_back(tmp);
}
