/*
Description: The progrma does the following
            - Reads a sequence of words from a txt file (data/words.txt)
            - Prints one of those words uniformly at random

Explaination: Using Knuth's method (not storing all words in an array) 
            select ith word with probability 1/i (replacing the previous
            champion word)
*/


#include <iostream> // std::cin, std::cout
#include <string>   // std::string
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <fstream>  // Reading from file

int main(int argc, char const *argv[]) {
    // Initialise random seed
    srand(time(NULL));
    // Gen random number between 0 and 1
    double r;

    // Var to hold normal, champion word and the filename
    std::string word;
    std::string champ_word;
    std::string file_name;

    std::cout << "Enter the file name: ";
    std::cin >> file_name;

    // Reading word by word from file
    std::ifstream file;
    file.open(file_name);
    
    int i = 1;
    while (file >> word) {
        // Random number
        r = ((double) rand() / (RAND_MAX));
        if (r < 1.0/i) {
            champ_word = word;
        }
        i += 1;
    }

    std::cout << "Chamption Word is " << champ_word << "\n";

    return 0;
}
