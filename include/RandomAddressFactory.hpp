#pragma once

#include <map>
#include <string>
#include <vector>

#include "Address.hpp"

class RandomAddressFactory {
public:
    Address makeRandomAddress() const;

private:
    const std::vector<std::string> sampleTowns {
        "Krakow",
        "Warsaw",
        "Wroclaw",
        "Poznan",
        "Gdansk",
        "Katowice",
        "Rzeszow",
        "Lodz",
        "Szczecin",
        "Bydgoszcz",
        "Lublin",
    };

    const std::map<std::string, std::string> sampleTownsWithPostalPrefix {
        { "Krakow", "30" },
        { "Warsaw", "02" },
        { "Wroclaw", "50" },
        { "Poznan", "60" },
        { "Gdansk", "80" },
        { "Katowice", "40" },
        { "Rzeszow", "35" },
        { "Lodz", "90" },
        { "Szczecin", "70" },
        { "Bydgoszcz", "85" },
        { "Lublin", "20" }
    };

    const std::vector<std::string> sampleStreets {
        "Aeroville",
        "Parkview Way",
        "Hazelnut Street",
        "Sugarplum Avenue",
        "Coastline Avenue",
        "Queenhithe",
        "Circus Lane",
        "Bloomfield Avenue",
        "Marine Boulevard",
        "Hope Lane",
        "Stone Boulevard",
        "Ivory Way",
        "Neckinger",
        "Phoenix Lane",
        "Grace Route",
        "Wharf Route",
        "Hind Lane",
        "Love Avenue",
        "Spruce Street",
        "Dylways"
    };

    int generateRandomNumber(int from, int upTo) const;
    std::string getRandomTown() const;
    std::string getRandomPostalCodeForTown(const std::string& town) const;
    std::pair<std::string, std::string> getTownWithPostalCode() const;
    std::string getRandomStreetName() const;
    std::string getRandomBuildingNumber() const;
};
