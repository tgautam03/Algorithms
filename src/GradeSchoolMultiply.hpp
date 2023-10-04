/*
Description: The basic (and inefficient) algorithm to multiply large 
            integer numbers taught in grade school.

Explaination: Base Cases:
            - Only Single Digit Multiplication allowed
            - Addition can be at max one double digit numbers 
            added to one single digit number
*/

#ifndef GRADESCHOOLMUL // include guard
#define GRADESCHOOLMUL

#include <iostream>
#include "utils.hpp"

// Function that performs multiplication
unsigned long multiply(unsigned long &num1, unsigned long &num2);

#endif