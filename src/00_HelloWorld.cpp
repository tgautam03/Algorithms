/*
Description: Just print Hello and Goodbye
*/

#include <iostream>
#include <string>

int main() {
    // Initialise using C++ string class
    std::string name1, name2;

    // Accept names as CLI
    std::cout << "Enter two names: \n";
    std::cin >> name1 >> name2;

    // Print output
    std::cout << "Hello " << name1 << " and " << name2 << "\n";
    std::cout << "Goodbye " << name1 << " and " << name2 << "\n";

    return 0;
}