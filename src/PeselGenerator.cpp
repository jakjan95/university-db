#include <random>

#include "PeselGenerator.hpp"

std::string PeselGenerator::generateFemaleRandomPesel() const
{
    auto genderRandomNumber = generateFemaleGenderNumber();
    std::string randomPesel = generatePeselDateAndSeriesPart() + std::to_string(genderRandomNumber);
    auto checksum = calculateChecksum(randomPesel);
    randomPesel += std::to_string(checksum);
    return randomPesel;
}

std::string PeselGenerator::generateMaleRandomPesel() const
{
    auto genderRandomNumber = generateMaleGenderNumber();
    std::string randomPesel = generatePeselDateAndSeriesPart() + std::to_string(genderRandomNumber);
    auto checksum = calculateChecksum(randomPesel);
    randomPesel += std::to_string(checksum);
    return randomPesel;
}

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
date::year_month_day PeselGenerator::generateRandomDate(TimePoint startingPoint, TimePoint endingPoint) const
{
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(endingPoint - startingPoint);
    std::mt19937 gen(std::random_device {}());
    std::uniform_int_distribution<std::chrono::seconds::rep> distrb(0, seconds.count());
    auto generatedDate = startingPoint + std::chrono::seconds(distrb(gen));
    return date::year_month_day(date::floor<date::days>(generatedDate));
}

date::year_month_day PeselGenerator::generateRandomDate() const
{
    auto hundredYearsAgoFromToday = std::chrono::system_clock::now() - std::chrono::hours(24 * 365 * 100);
    auto eighteenYearsAgoFromToday = std::chrono::system_clock::now() - std::chrono::hours(24 * 365 * 18);
    return generateRandomDate(hundredYearsAgoFromToday, eighteenYearsAgoFromToday);
}

std::string PeselGenerator::inserZeroBefore(std::string& value) const
{
    if (value.size() == 1) {
        value.insert(0, "0");
    }
    return value;
}

std::string PeselGenerator::generateRandomDatePeselPart() const
{
    auto randomDate = generateRandomDate();
    auto year = static_cast<int>(randomDate.year());
    auto month = static_cast<unsigned>(randomDate.month());
    auto day = static_cast<unsigned>(randomDate.day());

    if (year >= 1800 && year <= 1899) {
        month += 80;
    } else if (year >= 2000 && year <= 2099) {
        month += 20;
    } else if (year >= 2100 && year <= 2199) {
        month += 40;
    } else if (year >= 2200 && year <= 2299) {
        month += 60;
    }

    auto monthPart = std::to_string(month);
    auto dayPart = std::to_string(day);

    std::string datePeselPart = std::to_string(year).substr(2, 2) + inserZeroBefore(monthPart) + inserZeroBefore(dayPart);
    return datePeselPart;
}

std::string PeselGenerator::generateRandomNumberPart() const
{
    std::mt19937 gen(std::random_device {}());
    std::uniform_int_distribution<> distrb(0, 999);
    auto randomNumber = distrb(gen);
    auto randomNumberaAsString = std::to_string(randomNumber);
    if (randomNumberaAsString.size() == 1) {
        randomNumberaAsString.insert(0, "00");
    } else if (randomNumberaAsString.size() == 2) {
        randomNumberaAsString.insert(0, "0");
    }
    return randomNumberaAsString;
}

std::string PeselGenerator::generatePeselDateAndSeriesPart() const
{
    auto datePart = generateRandomDatePeselPart();
    auto randomNumberPart = generateRandomNumberPart();
    std::string randomPeselDateAndSeriesPart = datePart + randomNumberPart;
    return randomPeselDateAndSeriesPart;
}

size_t PeselGenerator::generateMaleGenderNumber() const
{
    constexpr std::array<size_t, 5> maleNumbers { 1, 3, 5, 7, 9 };
    std::mt19937 gen(std::random_device {}());
    std::uniform_int_distribution<> distrb(0, maleNumbers.size() - 1);
    return maleNumbers.at(distrb(gen));
}

size_t PeselGenerator::generateFemaleGenderNumber() const
{
    constexpr std::array<size_t, 5> femaleNumbers { 0, 2, 4, 6, 8 };
    std::mt19937 gen(std::random_device {}());
    std::uniform_int_distribution<> distrb(0, femaleNumbers.size() - 1);
    return femaleNumbers.at(distrb(gen));
}

size_t PeselGenerator::calculateChecksum(const std::string& pesel) const
{
    std::array<size_t, 10> peselArray {};
    for (size_t i = 0; i < pesel.size(); ++i) {
        peselArray[i] = pesel[i] - '0';
    }
    auto checksum = std::inner_product(peselArray.begin(), peselArray.end(), weights.begin(), 0);
    return (checksum % 10) == 0 ? 0 : 10 - (checksum % 10);
}
