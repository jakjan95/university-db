#pragma once

#include <string>

#include "date.h"

class PeselGenerator {
public:
    PeselGenerator() = default;

    std::string generateFemaleRandomPesel() const;
    std::string generateMaleRandomPesel() const;

private:
    const std::array<size_t, 10> weights { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };

    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
    date::year_month_day generateRandomDate(TimePoint startingPoint, TimePoint endingPoint) const;
    date::year_month_day generateRandomDate() const;

    std::string inserZeroBefore(std::string& value) const;
    std::string generateRandomDatePeselPart() const;
    std::string generateRandomNumberPart() const;
    std::string generatePeselDateAndSeriesPart() const;

    size_t generateMaleGenderNumber() const;
    size_t generateFemaleGenderNumber() const;

    size_t calculateChecksum(const std::string& pesel) const;
};
