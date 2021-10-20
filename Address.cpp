#include <iostream>

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

std::ostream& operator<<(std::ostream& out, const Address& adr)
{
    out << adr.postalCode_ << ' ' << adr.town_ << ", " << adr.street_ << ' ' << adr.buildingNumber_;
    if (adr.flatNumber_.has_value()) {
        out << '/' << adr.flatNumber_.value();
    }
    return out;
}

std::istream& operator>>(std::istream& in, Address& adr)
{
    std::cout << " *** Addres data form ***\n";
    std::cout << "Enter postal code [XX-XXX]: ";
    std::cin >> adr.postalCode_;
    std::cout << "Enter town: ";
    std::cin >> adr.town_;
    std::cout << "Enter street: ";
    std::cin >> adr.street_;
    std::cout << "Enter building number: ";
    std::cin >> adr.buildingNumber_;
    std::cout << "Is it flat? [Y/N]: ";
    char isFlat;
    std::cin >> isFlat;
    if (isFlat == 'Y' || isFlat == 'y') {
        std::cout << "Enter flat number: ";
        size_t flatNum;
        std::cin >> flatNum;
        adr.flatNumber_.emplace(flatNum);
    }
    return in;
}
