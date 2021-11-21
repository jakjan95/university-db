#include "RandomAddressFactory.hpp"

#include <cstddef>
#include <random>

Address RandomAddressFactory::makeRandomAddress() const
{
    auto [postalCode, town] = getTownWithPostalCode();
    auto street = getRandomStreetName();
    auto buildingNumber = getRandomBuildingNumber();
    if (generateRandomNumber(0, 1)) {
        auto flatNumber = generateRandomNumber(1, 150);
        return Address(postalCode, town, street, buildingNumber, flatNumber);
    }
    return Address(postalCode, town, street, buildingNumber);
}

int RandomAddressFactory::generateRandomNumber(int from, int upTo) const
{
    std::mt19937 gen(std::random_device {}());
    std::uniform_int_distribution<> distrb(from, upTo);
    return distrb(gen);
}

std::string RandomAddressFactory::getRandomTown() const
{
    return sampleTowns[generateRandomNumber(0, static_cast<int>(sampleTowns.size()) - 1)];
}

std::string RandomAddressFactory::getRandomPostalCodeForTown(const std::string& town) const
{
    auto postalPostfixAsNumber = generateRandomNumber(0, 999);
    auto postalPostfixAsString = std::to_string(postalPostfixAsNumber);
    if (postalPostfixAsString.size() == 1) {
        postalPostfixAsString.insert(0, "00");
    } else if (postalPostfixAsString.size() == 2) {
        postalPostfixAsString.insert(0, "0");
    }

    auto postalPrefix = sampleTownsWithPostalPrefix.at(town);
    auto polishPostalCodeSeparator { '-' };
    auto postalCode = postalPrefix + polishPostalCodeSeparator + postalPostfixAsString;
    return postalCode;
}

std::pair<std::string, std::string> RandomAddressFactory::getTownWithPostalCode() const
{
    auto town = getRandomTown();
    auto postalCode = getRandomPostalCodeForTown(town);
    return { town, postalCode };
}

std::string RandomAddressFactory::getRandomStreetName() const
{
    return sampleStreets[generateRandomNumber(0, static_cast<int>(sampleStreets.size()) - 1)];
}

std::string RandomAddressFactory::getRandomBuildingNumber() const
{
    auto buildingNumberValue = generateRandomNumber(1, 250);
    std::string buildingNumber = std::to_string(buildingNumberValue);
    if (generateRandomNumber(0, 1)) {
        constexpr int upperLetterA = 65;
        constexpr int upperLetterZ = 90;
        auto letter = static_cast<char>(generateRandomNumber(upperLetterA, upperLetterZ));
        buildingNumber.push_back(letter);
    }
    return buildingNumber;
}
