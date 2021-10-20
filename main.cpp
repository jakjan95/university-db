#include <iostream>

#include "Address.hpp"

int main()
{
    //Supports addresses like: 12-456 City Street 15A (10)
    Address adr { "12-456", "City", "Sesame street", "15A" };
    Address adr2 { "12-456", "City", "Sesame street", "15A", 10 };
    std::cout << adr << '\n';
    std::cout << adr2 << '\n';
    return 0; 
}
