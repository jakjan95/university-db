#include <iostream>

#include "Address.hpp"
#include "Student.hpp"
#include "Database.hpp"

void testAddres()
{
    //Supports addresses like: 12-456 City Street 15A (10)
    Address adr { "12-456", "City", "Sesame street", "15A" };
    Address adr2 { "12-456", "City", "Sesame street", "15A", 10 };
    std::cout << adr << '\n';
    std::cout << adr2 << '\n';
    // std::cin >> adr2 ;
    // std::cout << adr2 << '\n';
}

void testStudent()
{
    Address adr2 { "12-456", "City", "Sesame street", "15A", 10 };
    Student stud1 { "Jack", "Sparrow", adr2, 21392, "93010583751", Student::Gender::male };
    std::cout << stud1 << '\n';
    Student stud2;
    // std::cin >> stud2;
    std::cout << stud2 << '\n';
}

int main()
{
    testAddres();
    testStudent();
    Database database;
    database.run();
    return 0;
}
