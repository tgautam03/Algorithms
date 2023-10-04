#include <iostream>
#include "KaratsubaMultiply.hpp"

#include <cmath>

unsigned long karatsuba_multiply(unsigned long &num1, unsigned long &num2)
{
    // Initialising vectors for two nunbers and the final answer
    std::vector <int> v_num1;
    std::vector <int> v_num2;
    unsigned long final_ans;

    // Get digits
    get_digits(v_num1, num1);
    get_digits(v_num2, num2);

    // Final Answer
    final_ans = recursive_call(v_num1, v_num2);

    // std::cout << final_ans << "\n";

    return final_ans;
}

std::vector<int> add(std::vector<int>v_num1, std::vector<int>v_num2)
{
    // Make both digits equal size
    if (v_num1.size() > v_num2.size())
    {
        int diff = v_num1.size() - v_num2.size();

        for (int i = 0; i < diff; i++)
            v_num2.insert(v_num2.begin(), 0);
    }

    if (v_num1.size() < v_num2.size())
    {
        int diff = v_num2.size() - v_num1.size();

        for (int i = 0; i < diff; i++)
            v_num1.insert(v_num1.begin(), 0);
    }

    // Final ans
    std::vector<int> final_ans;

    int carry = 0;
    for (int i = v_num2.size()-1; i >= 0; i--)
    {
        int add = v_num1[i] + v_num2[i] + carry;
        final_ans.insert(final_ans.begin(), add % 10);
        carry = add / 10;
    }
    if (carry > 0)
        final_ans.insert(final_ans.begin(), carry);

    return final_ans;
}

unsigned long recursive_call(std::vector<int>v_num1, std::vector<int>v_num2)
{
    if (v_num1.size() == 1 && v_num2.size() == 1)
        return (unsigned long)v_num1[0]*v_num2[0];
    else
    {
        // // Make both digits equal size
        if (v_num1.size() > v_num2.size())
        {
            int diff = v_num1.size() - v_num2.size();

            for (int i = 0; i < diff; i++)
                v_num2.insert(v_num2.begin(), 0);
        }

        if (v_num1.size() < v_num2.size())
        {
            int diff = v_num2.size() - v_num1.size();

            for (int i = 0; i < diff; i++)
                v_num1.insert(v_num1.begin(), 0);
        }

        // Correct for odd number of digits
        if (v_num1.size() % 2 == 1)
            v_num1.insert(v_num1.begin(), 0);

        if (v_num2.size() % 2 == 1)
            v_num2.insert(v_num2.begin(), 0);

        // Split into a, b, c, d
        int num1_count = v_num1.size();
        int num2_count = v_num2.size();
        int n;

        if (num1_count > num2_count)
            n = num1_count;
        else if (num2_count > num1_count)
            n = num2_count;
        else
            n = num1_count;
        
        int nby2 = n / 2;
        
        // Split into a, b, c, d
        std::vector<int> a = std::vector<int>(v_num1.begin(), v_num1.begin()+nby2);
        std::vector<int> b = std::vector<int>(v_num1.begin()+nby2, v_num1.end());
        
        std::vector<int> c = std::vector<int>(v_num2.begin(), v_num2.begin()+nby2);
        std::vector<int> d = std::vector<int>(v_num2.begin()+nby2, v_num2.end());

        unsigned long ac = recursive_call(a, c);
        unsigned long bd = recursive_call(b,d);
        std::vector<int> aPlusb = add(a, b);
        std::vector<int> cPlusd = add(c, d);
        unsigned long abcd = recursive_call(aPlusb, cPlusd);
        unsigned long ad_bc = abcd - bd - ac;

        return (pow(10, n)*ac) + (pow(10, nby2)*(ad_bc)) + bd;
    }
}