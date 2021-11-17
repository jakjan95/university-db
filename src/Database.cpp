#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "Database.hpp"
#include "Student.hpp"

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
    case Option::DeleteStudentRecord:
        deleteStudentRecord();
        break;
    case Option::PrintMenu:
        printMenu();
        break;
    case Option::SaveDatabaseToFile:
        saveDatabaseToFile();
        break;
    case Option::ReadDatabaseFromFile:
        readDatabaseFromFile();
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
    std::cout << "  7   DELETE STUDENT RECORD\n";
    std::cout << "  8   PRINT MENU\n";
    std::cout << "  9   SAVE DATABASE TO FILE\n";
    std::cout << " 10   READ DATABASE FROM FILE\n";
    std::cout << "  0   QUIT\n";
    std::cout << "=============================================\n";
}

void Database::quit()
{
    std::cout << " QUITTING THE PROGRAM....... \n";
    data_.clear();
    std::exit(0);
}

Address Database::createAddress()
{
    std::cout << " *** Addres data form ***\n";
    std::cout << "Enter postal code [XX-XXX]: ";
    std::string postalCode;
    std::cin >> postalCode;
    std::cout << "Enter town: ";
    std::string town;
    std::cin.ignore();
    std::getline(std::cin, town);
    std::cout << "Enter street: ";
    std::string street;
    std::getline(std::cin, street);
    std::cout << "Enter building number: ";
    std::string buildingNumber;
    std::cin >> buildingNumber;

    Address tmpAddress { postalCode, town, street, buildingNumber };

    std::cout << "Is it flat? [Y/N]: ";
    char isFlat;
    std::cin >> isFlat;
    if (isFlat == 'Y' || isFlat == 'y') {
        std::cout << "Enter flat number: ";
        size_t flatNum;
        std::cin >> flatNum;
        tmpAddress.setFlatNumber(flatNum);
    }
    return tmpAddress;
}

void Database::addStudent()
{
    std::cout << " *** Student data form ***\n";
    std::cout << "Enter name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Enter surname: ";
    std::string surname;
    std::cin >> surname;
    std::cout << "Enter student number: ";
    size_t studentNumber;
    std::cin >> studentNumber;
    std::cout << "Enter gender [M/F]: ";
    char gen;
    std::cin >> gen;
    auto gender = GenderTools::getUserGenderFromChar(gen);
    std::cout << "Enter pesel: ";
    std::string pesel;
    std::cin >> pesel;

    while (!isGivenPeselValid(pesel, gender)) {
        std::cout << "Pesel is invalid, enter again:";
        std::cin >> pesel;
    }

    auto tmpAddress = createAddress();
    auto tmpStudent = std::make_unique<Student>(name, surname, tmpAddress, studentNumber, pesel, gender);
    data_.emplace_back(std::move(tmpStudent));
}

void Database::printIndexRow()
{
    std::cout << " ______________ "
              << "______________ "
              << "____________________________________________________________ "
              << "______________ "
              << "________ "
              << "________ "
              << "________ " << '\n';
    std::cout << "|     NAME     |"
              << "   SURNAME    |"
              << "                          ADDRESS                           |"
              << "    PESEL     |"
              << " GENDER |"
              << " INDEX  |" 
              << " SALARY |" << '\n';
    std::cout << " -------------- "
              << "-------------- "
              << "------------------------------------------------------------ "
              << "-------------- "
              << "-------- "
              << "-------- "
              << "-------- " << '\n';
}

void Database::displayDatabase()
{
    printIndexRow();
    for (const auto& el : data_) {
        std::cout << *el << '\n';
    }
    std::cout << ' ' << std::string(133, '-') << '\n';
}

void Database::addTestData()
{
    auto testStudent1 = std::make_unique<Student>("Jack", "Sparrow",
        Address { "00-001", "Warsaw", "Kwiatowa", "5", 3 }, 2102, "05211938254", Gender::male);
    auto testStudent2 = std::make_unique<Student>("Jennifer", "Smith",
        Address { "31-403", "Krakow", "Owocowa", "99", 6 }, 2106, "84102367182", Gender::female);
    auto testStudent3 = std::make_unique<Student>("Betty", "Williams",
        Address { "50-054", "Wroclaw", "Wielkiego Bohatera", "15A", 10 }, 2100, "73032726648", Gender::female);
    auto testStudent4 = std::make_unique<Student>("Susan", "Baker",
        Address { "40-000", "Katowice", "Wielkiego Artysty", "150" }, 2193, "96083054267", Gender::female);
    auto testStudent5 = std::make_unique<Student>("Richard", "Clark",
        Address { "60-001", "Poznan", "Warszawska", "121A", 95 }, 2152, "95011572158", Gender::male);
    auto testStudent6 = std::make_unique<Student>("Brian", "Harrison",
        Address { "70-445", "Lodz", "Wodnej rury", "15" }, 2109, "67010349198", Gender::male);
    data_.emplace_back(std::move(testStudent1));
    data_.emplace_back(std::move(testStudent2));
    data_.emplace_back(std::move(testStudent3));
    data_.emplace_back(std::move(testStudent4));
    data_.emplace_back(std::move(testStudent5));
    data_.emplace_back(std::move(testStudent6));
}

void Database::searchBySurname()
{
    std::cout << " ENTER SURNAME: ";
    std::string surname;
    std::cin >> surname;
    auto it = std::find_if(data_.cbegin(), data_.cend(),
        [&surname](const auto& el) { return surname == el->getSurname(); });

    if (it != data_.cend()) {
        std::cout << *(*it) << '\n';
    } else {
        std::cout << " STUDENT WITH SURNAME " << surname << " NOT FOUND!\n";
    }
}

void Database::searchByPesel()
{
    std::cout << " ENTER PESEL: ";
    std::string pesel;
    std::cin >> pesel;
    auto it = std::find_if(data_.cbegin(), data_.cend(),
        [&pesel](const auto& el) { return pesel == el->getPesel(); });

    if (it != data_.cend()) {
        std::cout << *(*it) << '\n';
    } else {
        std::cout << " STUDENT WITH PESEL " << pesel << " NOT FOUND!\n";
    }
}

void Database::sortByPesel()
{
    std::cout << " SORTING BY PESEL\n";
    std::sort(data_.begin(), data_.end(),
        [](const auto& lhs, const auto& rhs) { return std::stoul(lhs->getPesel()) < std::stoul(rhs->getPesel()); });
}

void Database::sortBySurname()
{
    std::cout << " SORTING BY SURNAME\n";
    std::sort(data_.begin(), data_.end(),
        [](const auto& lhs, const auto& rhs) { return lhs->getSurname() < rhs->getSurname(); });
}

void Database::deleteStudentRecord()
{
    std::cout << " ENTER STUDENT INDEX TO DELETE: ";
    size_t index;
    std::cin >> index;
    data_.erase(std::remove_if(data_.begin(), data_.end(),
                    [&index](const auto& el) {
                        return dynamic_cast<Student*>(el.get()) == nullptr ? false : dynamic_cast<Student&>(*el).getStudentNumber() == index;
                    }),
        data_.end());
}

void Database::saveDatabaseToFile()
{
    std::cout << " SAVE DATABASE AS: ";
    std::string filneName;
    std::cin >> filneName;

    if (filneName != "") {
        std::ofstream output { filneName, std::ios_base::out };
        if (output.is_open()) {
            for (const auto& el : data_) {
                output << *el << '\n';
            }
            output.close();
        } else {
            std::cout << "CANNOT OPEN A FILE!\n";
        }
    } else {
        std::cout << "NO FILE NAME PROVIDED!\n";
    }
}

void Database::readDatabaseFromFile()
{
    std::cout << " READ DATABASE FROM FILE: ";
    std::string filneName;
    std::cin >> filneName;

    std::ifstream ifs { filneName, std::ios_base::in };
    if (ifs.is_open()) {
        for (std::string line; std::getline(ifs, line);) {
            if (!line.empty()) {
                auto tmp = std::make_unique<Student>();
                std::stringstream ss { line };
                ss >> *tmp;
                data_.emplace_back(std::move(tmp));
            }
        }
        std::cout << " DONE!\n";
        ifs.close();
    } else {
        std::cout << " CANNOT OPEN A FILE" << filneName << "!\n";
    }
}

bool Database::isBirthdateValidForPesel(const std::string& pesel)
{
    auto monthPart = std::stoi(pesel.substr(2, 2));
    constexpr std::array<size_t, 4> additionalMonthNumber = { 80, 20, 40, 60 };
    auto isMonthNumberValid = std::any_of(additionalMonthNumber.cbegin(), additionalMonthNumber.cend(),
                                  [monthPart](const auto& el) {
                                      return monthPart % el < 1 || monthPart % el > 12;
                                  })
        || (monthPart > 0 && monthPart <= 12);

    if (!isMonthNumberValid) {
        return false;
    }

    auto dayPart = std::stoi(pesel.substr(4, 2));
    if (dayPart < 0 || dayPart > 31) {
        return false;
    }

    return true;
}

bool Database::isGenderValidForPesel(const std::string& pesel, Gender gender)
{
    auto genderInformationNumber = pesel[9] - '0';
    return (gender == Gender::male && genderInformationNumber % 2 != 0)
        || (gender == Gender::female && genderInformationNumber % 2 == 0);
}

bool Database::isPeselCheckSumValid(const std::string& pesel)
{
    constexpr std::array<size_t, 10> weights { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };
    std::array<size_t, 10> peselArray {};
    for (size_t i = 0; i < pesel.size(); ++i) {
        peselArray[i] = pesel[i] - '0';
    }
    auto checksum = std::inner_product(peselArray.begin(), peselArray.end(), weights.begin(), 0);
    auto expectedLastNumber = (checksum % 10) == 0 ? 0 : 10 - (checksum % 10);
    auto lastNumberInPesel = pesel[10] - '0';
    return lastNumberInPesel == expectedLastNumber;
}

bool Database::isGivenPeselValid(const std::string& pesel, Gender gender)
{
    if (pesel.length() != 11 || pesel.empty()) {
        return false;
    }

    if (!isBirthdateValidForPesel(pesel)) {
        return false;
    }

    if (!isGenderValidForPesel(pesel, gender)) {
        return false;
    }

    if (!isPeselCheckSumValid(pesel)) {
        return false;
    }
    return true;
}
