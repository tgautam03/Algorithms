#include "GradeSchoolMultiply.hpp"

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