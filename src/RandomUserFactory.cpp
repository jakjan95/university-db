#include "RandomUserFactory.hpp"

#include <cstddef>
#include <random>

#include "Employee.hpp"
#include "Student.hpp"

std::unique_ptr<User> RandomUserFactory::makeRandomUser() const
{
    std::string name {};
    auto surname = generateRandomSurname();
    std::string pesel {};
    auto gender = Gender::undefined;
    auto addres = adrFact.makeRandomAddress();

    if (generateRandomNumber(0, 1)) {
        name = generateRandomFemaleName();
        pesel = peselGen.generateFemaleRandomPesel();
        gender = Gender::female;
    } else {
        name = generateRandomMaleName();
        pesel = peselGen.generateMaleRandomPesel();
        gender = Gender::male;
    }

    std::unique_ptr<User> user = nullptr;
    auto probabilityOfGeneratingEmployee = generateRandomNumber(0, 100);
    if (probabilityOfGeneratingEmployee >= 70) {
        auto salary = generateRandomNumber(4000, 10000);
        user.reset(dynamic_cast<User*>(new Employee(name, surname, addres, pesel, gender, salary)));
    } else {
        auto studentNumber = generateRandomNumber(2000, 3999);
        user.reset(dynamic_cast<User*>(new Student(name, surname, addres, studentNumber, pesel, gender)));
    }

    return user;
}

size_t RandomUserFactory::generateRandomNumber(size_t from, size_t upTo) const
{
    std::mt19937 gen(std::random_device {}());
    std::uniform_int_distribution<size_t> distrb(from, upTo);
    return distrb(gen);
}

std::string RandomUserFactory::generateRandomSurname() const
{
    return surnames[generateRandomNumber(0, surnames.size() - 1)];
}

std::string RandomUserFactory::generateRandomFemaleName() const
{
    return femaleNames[generateRandomNumber(0, femaleNames.size() - 1)];
}

std::string RandomUserFactory::generateRandomMaleName() const
{
    return maleNames[generateRandomNumber(0, maleNames.size() - 1)];
}
