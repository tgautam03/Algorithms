/*
Description: Algorithms to multiply large integer numbers.
*/

#include <iostream>
#include <cassert>

#include "../src/GradeSchoolMultiply.hpp"
#include "../src/KaratsubaMultiply.hpp"

int main(int argc, char const *argv[])
{
    // The two numbers to be multiplied
    unsigned long num1, num2;

    // Accept them via user input
    std::cout << "Enter 1st Integer Number: ";
    std::cin >> num1;
    std::cout << "Enter 2nd Integer Number: ";
    std::cin >> num2;

    // Confirming entered numbers
    std::cout << num1 << " * " << num2 << " = \n";

    // Multiply
    unsigned long std_ans = multiply(num1, num2);
    std::cout << "Standard: " << std_ans << "\n";
    unsigned long ksb_ans = karatsuba_multiply(num1, num2);
    std::cout << "Karatsuba: " << ksb_ans << "\n";

    // Asserting
    std::cout << "Checking standard multiplication...\n";
    assert(std_ans == num1 * num2);
    std::cout << "DONE!\n";

    std::cout << "Checking karatsuba multiplication...\n";
    assert(ksb_ans == num1 * num2);
    std::cout << "DONE!\n";

    return 0;
}