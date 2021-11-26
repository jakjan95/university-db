#pragma once

#include <array>
#include <cstddef>
#include <memory>
#include <string>

#include "PeselGenerator.hpp"
#include "RandomAddressFactory.hpp"

class User;

class RandomUserFactory {
public:
    std::unique_ptr<User> makeRandomUser() const;

private:
    const PeselGenerator peselGen;
    const RandomAddressFactory adrFact;

    const std::array<std::string, 32> surnames {
        "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
        "Hernandez", "Lopez", "Gonzales", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin",
        "Lee", "Perez", "Thompson", "White", "Harris", "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson", "Walker", "Young"
    };

    const std::array<std::string, 32> femaleNames {
        "Olivia", "Emma", "Amelia", "Ava", "Sophia", "Charlotte", "Isabella", "Mia", "Luna", "Harper", "Gianna",
        "Evelyn", "Aria", "Ella", "Ellie", "Mila", "Layla", "Avery", "Camila", "Lily", "Scarlett", "Sofia",
        "Nova", "Aurora", "Chloe", "Riley", "Nora", "Hazel", "Abigail", "Rylee", "Penelope", "Elena"
    };

    const std::array<std::string, 32> maleNames {
        "Liam", "Noah", "Oliver", "Elijah", "Lucas", "Levi", "Mason", "Asher", "James", "Ethan", "Mateo", "Leo",
        "Jack", "Benjamin", "Aiden", "Logan", "Samuel", "Jacob", "Henry", "Wyatt", "Sebastian", "Carter", "Daniel",
        "William", "Alexander", "Ezra", "Owen", "Michael", "Muhammad", "Julian", "Hudson", "Luke"
    };

    size_t generateRandomNumber(size_t from, size_t upTo) const;
    std::string generateRandomSurname() const;
    std::string generateRandomFemaleName() const;
    std::string generateRandomMaleName() const;
};
