/*
Description: All the utility functions
*/

#ifndef UTILS // include guard
#define UTILS

#include <iostream>

// Function that collects all digits of the integer number
void get_digits(std::vector<int>& digits, unsigned long num);

// Function that converts vector into the number
unsigned long get_number(std::vector<int>& digits);


#endif