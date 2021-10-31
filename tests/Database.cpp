#include "gtest/gtest.h"
#include <string>

#include "Database.hpp"

TEST(DatabasePeselValidation, PeselsShouldBeValid)
{
    Database cut;

    const auto female = Student::Gender::female;
    const auto male = Student::Gender::male;

    const std::string validFemalePesel = "46122028562";
    const std::string validMalePesel = "50091733974";

    EXPECT_TRUE(cut.isGivenPeselValid(validFemalePesel, female));
    EXPECT_TRUE(cut.isGivenPeselValid(validMalePesel, male));
}

TEST(DatabasePeselValidation, PeselsShouldBeInvalid)
{
    Database cut;

    const auto female = Student::Gender::female;
    const auto male = Student::Gender::male;

    const std::string peselWithInvalidChecksum1 = "84071791635";
    const std::string peselWithInvalidChecksum2 = "12213197221";

    const std::string invalidFemalePesel = "46122028592";
    const std::string invalidMalePesel = "50091733984";

    const std::string peselWithInvalidBirthday1 = "95130946407";
    const std::string peselWithInvalidBirthday2 = "90083201443";

    EXPECT_FALSE(cut.isGivenPeselValid(peselWithInvalidChecksum1, male));
    EXPECT_FALSE(cut.isGivenPeselValid(peselWithInvalidChecksum2, female));
    EXPECT_FALSE(cut.isGivenPeselValid(invalidFemalePesel, female));
    EXPECT_FALSE(cut.isGivenPeselValid(invalidMalePesel, male));
    EXPECT_FALSE(cut.isGivenPeselValid(peselWithInvalidBirthday1, female));
    EXPECT_FALSE(cut.isGivenPeselValid(peselWithInvalidBirthday2, female));
}
