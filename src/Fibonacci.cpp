#include "Fibonacci.hpp"

long long fibrecurs(long long n)
{
    if (n <= 1)
        return n;
    else
        return fibrecurs(n-1) + fibrecurs(n-2);
}


long long fibhand(long long n)
{
    // Edge Cases
    if (n == 0)
        return 0;
    
    else if (n == 1)
        return 1;
    
    // Standard Case
    else
    {
        // Variable to store F(0)
        long long Fn_minus_2 = 0;
        // Variable to store F(1)
        long long Fn_minus_1 = 1;

        // Variable to store F(n)
        long long Fn;

        // Loop over all number before n
        for (int i = 2; i < n+1; i++)
        {
            Fn = Fn_minus_1 + Fn_minus_2;
            Fn_minus_2 = Fn_minus_1;
            Fn_minus_1 = Fn;    
        }
        
        return Fn;
    }
}