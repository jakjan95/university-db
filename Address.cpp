#include <algorithm>
#include <cctype>
#include <iostream>
#include <istream>
#include <string>

#include "Address.hpp"

Address::Address(const std::string& postalCode, const std::string& town, const std::string& street,
    const std::string& buildingNumber, std::optional<size_t> flatNumber)
    : postalCode_ { postalCode }
    , town_ { town }
    , street_ { street }
    , buildingNumber_ { buildingNumber }
    , flatNumber_ { flatNumber }
{
}

std::string Address::getAddressString() const
{
    std::stringstream ss;
    ss << postalCode_ << ' ' << town_ << ", " << street_ << ' ' << buildingNumber_;
    if (flatNumber_.has_value()) {
        ss << '/' << flatNumber_.value();
    }
    return ss.str();
}

std::ostream& operator<<(std::ostream& out, const Address& adr)
{
    out << adr.getAddressString();
    return out;
}

std::istream& operator>>(std::istream& in, Address& adr)
{
    in >> adr.postalCode_ >> std::ws;
    std::getline(in, adr.town_, ',');

    std::cin >> std::ws;
    std::string streetWithNumber;
    std::getline(in, streetWithNumber);
    size_t posOfBuildingNumber { 0 };
    for (; posOfBuildingNumber < streetWithNumber.length(); ++posOfBuildingNumber) {
        if (isdigit(streetWithNumber[posOfBuildingNumber])) {
            break;
        }
    }
    std::string streetPart = streetWithNumber.substr(0, posOfBuildingNumber - 1);
    adr.street_ = streetPart;
    std::string buildingNumberString = streetWithNumber.substr(posOfBuildingNumber, streetWithNumber.length() - 1);

    auto isAddressForFlat = std::any_of(buildingNumberString.cbegin(), buildingNumberString.cend(),
        [](const auto& el) { return el == '/'; });
    if (isAddressForFlat) {
        std::stringstream ss { buildingNumberString };
        std::string buidlingNumberPart;
        std::getline(ss, buidlingNumberPart, '/');
        adr.buildingNumber_ = buidlingNumberPart;
        size_t flatNumberPart;
        ss >> flatNumberPart;
        adr.setFlatNumber(flatNumberPart);
    } else {
        adr.buildingNumber_ = buildingNumberString;
        adr.resetFlatNumber();
    }

    return in;
}
