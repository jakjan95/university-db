#pragma once

#include <optional>
#include <string>
#include <sstream>

class Address {
public:
    Address() = default;

    Address(const std::string& postalCode, const std::string& town, const std::string& street,
        const std::string& buildingNumber, std::optional<size_t> flatNumber = std::nullopt);

    friend std::ostream& operator<<(std::ostream& out, const Address& adr);
    friend std::istream& operator>>(std::istream& in, Address& adr);

private:
    std::string getAddressString() const;

    std::string postalCode_;
    std::string town_;
    std::string street_;
    std::string buildingNumber_;
    std::optional<size_t> flatNumber_;
};
