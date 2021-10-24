#include <algorithm>
#include <iostream>

#include "Database.hpp"

void Database::run()
{
    addTestData();
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
        displayDatabase();
        break;
    case Option::SearchBySurname:
        searchBySurname();
        break;
    case Option::SearchByPesel:
        searchByPesel();
        break;
    case Option::SortByPesel:
        sortByPesel();
        break;
    case Option::SortBySurname:
        sortBySurname();
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

void Database::printIndexRow()
{
    std::cout << " ___________ "
              << "______________ "
              << "____________________________________________________________ "
              << "________ "
              << "______________ "
              << "________" << '\n';
    std::cout << "|    NAME   |"
              << "   SURNAME    |"
              << "                          ADDRESS                           |"
              << " INDEX  |"
              << "    PESEL     |"
              << " GENDER |" << '\n';
    std::cout << " ----------- "
              << "-------------- "
              << "------------------------------------------------------------ "
              << "-------- "
              << "-------------- "
              << "-------- " << '\n';
}

void Database::displayDatabase()
{
    printIndexRow();
    for (const auto& el : data_) {
        std::cout << el << '\n';
    }
}

void Database::addTestData()
{
    Student testStudent1 { "Jack", "Sparrow",
        Address { "00-001", "Warsaw", "Kwiatowa", "5", 3 }, 2102, 91060427651, Student::Gender::male };
    Student testStudent2 { "Jennifer", "Smith",
        Address { "31-403", "Krakow", "Owocowa", "99", 6 }, 2106, 89010583751, Student::Gender::female };
    Student testStudent3 { "Betty", "Williams",
        Address { "50-054", "Wroclaw", "Wielkiego Bohatera", "15A", 10 }, 2100, 76010576751, Student::Gender::female };
    Student testStudent4 { "Susan", "Baker",
        Address { "40-000", "Katowice", "Wielkiego Artysty", "150" }, 2193, 90010583314, Student::Gender::female };
    Student testStudent5 { "Richard", "Clark",
        Address { "60-001", "Poznan", "Warszawska", "121A", 95 }, 2152, 99010488751, Student::Gender::male };
    Student testStudent6 { "Brian", "Harrison",
        Address { "70-445", "Lodz", "Wodnej rury", "15" }, 2109, 65012783785, Student::Gender::male };
    data_.emplace_back(testStudent1);
    data_.emplace_back(testStudent2);
    data_.emplace_back(testStudent3);
    data_.emplace_back(testStudent4);
    data_.emplace_back(testStudent5);
    data_.emplace_back(testStudent6);
}

void Database::searchBySurname()
{
    std::cout << " ENTER SURNAME: ";
    std::string surname;
    std::cin >> surname;
    auto it = std::find_if(data_.cbegin(), data_.cend(),
        [&surname](const auto& el) { return surname == el.getSurname(); });

    if (it != data_.cend()) {
        std::cout << *it << '\n';
    } else {
        std::cout << " STUDENT WITH SURNAME " << surname << " NOT FOUND!\n";
    }
}

void Database::searchByPesel()
{
    std::cout << " ENTER PESEL: ";
    size_t pesel;
    std::cin >> pesel;
    auto it = std::find_if(data_.cbegin(), data_.cend(),
        [&pesel](const auto& el) { return pesel == el.getPesel(); });

    if (it != data_.cend()) {
        std::cout << *it << '\n';
    } else {
        std::cout << " STUDENT WITH PESEL " << pesel << " NOT FOUND!\n";
    }
}

void Database::sortByPesel()
{
    std::cout << " SORTING BY PESEL\n";
    std::sort(data_.begin(), data_.end(),
        [](const auto& lhs, const auto& rhs) { return lhs.getPesel() < rhs.getPesel(); });
}

void Database::sortBySurname()
{
    std::cout << " SORTING BY SURNAME\n";
    std::sort(data_.begin(), data_.end(),
        [](const auto& lhs, const auto& rhs) { return lhs.getSurname() < rhs.getSurname(); });
}
