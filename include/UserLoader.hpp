#pragma once

#include <iostream>
#include <memory>

class User;

class UserLoader {
public:
    UserLoader() = default;
    User* getUserData() { return user.release(); }
    friend std::istream& operator>>(std::istream& in, UserLoader& userLoader);

private:
    std::unique_ptr<User> user { nullptr };
};
