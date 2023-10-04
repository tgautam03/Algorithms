/*
Description: The basic (and inefficient) algorithm to multiply large 
            integer numbers taught in grade school.

Explaination: Base Cases:
            - Only Single Digit Multiplication allowed
*/

#ifndef KARATSUBAMUL // include guard
#define KARATSUBAMUL

#include <iostream>
#include "utils.hpp"
#include <tuple>

// Function that adds two large numbers
std::vector<int> add(std::vector<int>v_num1, std::vector<int>v_num2);

// Functions that performs multiplication
unsigned long karatsuba_multiply(unsigned long &num1, unsigned long &num2);

// Recursive call to compute multiplication
unsigned long recursive_call(std::vector<int>v_num1, std::vector<int>v_num2);

#endif