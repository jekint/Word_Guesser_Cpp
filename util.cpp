// util.cpp

#define _CRT_SECURE_NO_DEPRECATE

#include "util.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <random>
#include <utility>
using namespace std;

// Replace below variable with the correct file location
// of the text file that will contain all the usable words
const char WORDFILENAME[] = "C:/Users/Jekin Tilva/Desktop/Coding Projects/word_guesser/words.txt";

// This function will load the words from the text file provided above into the character 2d-array
int loadWords(char words[][MAXWORDLEN + 1], int maxWords)
{
    ifstream wordfile(WORDFILENAME);
    if (!wordfile)
    {
        cout << "Cannot open " << WORDFILENAME << "!" << endl;
        return -1;
    }
    const int MAXFILELINELEN = 10000;
    char line[MAXFILELINELEN];
    int numWords = 0;
    while (wordfile.getline(line, MAXFILELINELEN))
    {
        if (numWords == maxWords)
        {
            cout << "Using only the first " << numWords << " words from "
                << WORDFILENAME << "." << endl;
            break;
        }

        // Store only words with the right number of lower case letters

        int k;
        for (k = 0; islower(line[k]); k++)
            ;

        // The following two lines fix a potential issue for non-Windows
        // users and are harmless for Windows users.

        if (line[k] == '\r')
            line[k] = '\0';

        if (line[k] == '\0' && k >= MINWORDLEN && k <= MAXWORDLEN)
        {
            strcpy(words[numWords], line);
            numWords++;
        }
    }
    return numWords;
}

// This function will return a random int between min and max
int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distro(min, max);
    return distro(generator);
}