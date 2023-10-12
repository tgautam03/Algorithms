#include <iostream>

#include "../src/Fibonacci.hpp"

int main(int argc, char const *argv[])
{
    // Variable to store number
    long long n;

    std::cout << "Enter the Number: ";
    std::cin >> n;

    // Computing Fibonacci number
    long long Fn1 = fibrecurs(n);
    long long Fn2 = fibhand(n);
    std::cout << "F(n)=" << Fn1 << "\n";
    std::cout << "F(n)=" << Fn2 << "\n";

    return 0;
}
