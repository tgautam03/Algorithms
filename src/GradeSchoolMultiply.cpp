/*
Description: The basic (and inefficient) algorithm to multiply large 
            integer numbers taught in grade school.

Explaination: Base Cases:
            - Only Single Digit Multiplication allowed
            - Addition can be at max one double digit numbers 
            added to one single digit number
*/

#include <iostream>
#include <math.h>
#include <cassert>

// Function that collects all digits of the integer number
void get_digits(std::vector<int>& digits, unsigned long num);

// Function that converts vector into the number
unsigned long get_number(std::vector<int>& digits);

// Function that performs multiplication
unsigned long multiply(unsigned long &num1, unsigned long &num2);

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
    std::cout << num1 << " * " << num2 << " = ";

    // Multiply
    unsigned long ans = multiply(num1, num2);

    std::cout << ans << "\n";

    // Asserting
    assert(ans == num1 * num2);

    return 0;
}

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

unsigned long multiply(unsigned long &num1, unsigned long &num2)
{
    // Initialising vectors for two nunbers and the final answer
    std::vector <int> v_num1;
    std::vector <int> v_num2;
    unsigned long final_ans;
    
    // Get digits
    get_digits(v_num1, num1);
    get_digits(v_num2, num2);

    // Multiplication
    std::vector<std::vector<int> > rows;
    int count = 0;
    for (int i = v_num2.size()-1; i >= 0; i--)
    {
        int n2 = v_num2[i];
        int carry = 0;
        std::vector<int> row;

        // Add zeros at the end
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                row.push_back(0);
            }
        }
        
        for (int j = v_num1.size()-1; j >= 0; j--)
        {
            int n1 = v_num1[j];
            int mul = n1 * n2;
            int ans = mul + carry;
            int ones_digit = ans % 10;
            carry = (ans/10)%10;

            row.push_back(ones_digit);
        }
        if (carry > 0)
            row.push_back(carry);

        rows.push_back(row);

        count++;
    }

    for (int i = 1; i < rows.size(); i++)
    {
        int carry = 0;
        for (int j = 0; j < rows[i].size(); j++)
        {
            int add;
            if (j < rows[i-1].size())
                add = rows[i-1][j] + rows[i][j];
            else
                add = rows[i][j];
            
            int ans = add + carry;

            rows[i][j] = ans % 10;
            carry = (ans / 10) % 10;
        }
        if (carry > 0)
            rows[i].push_back(carry);
    }

    // Storing the final answer
    final_ans = get_number(rows[rows.size()-1]);
    
    
    return final_ans;
}