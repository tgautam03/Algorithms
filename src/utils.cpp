#include "utils.hpp"

void get_digits(std::vector<int>& digits, unsigned long num) 
{   
    if (num > 9) {
        get_digits(digits, num / 10);
    }
    digits.push_back(num % 10);
}

unsigned long get_number(std::vector<int>& digits) 
{
    // Reverse the vector
    std::reverse(digits.begin(), digits.end());

    unsigned long num = digits[0];

    for (int i; i < digits.size(); i++)  
    {
        num = num * 10 + digits[i];
    }
    
    return num;
}

