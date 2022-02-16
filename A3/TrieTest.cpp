/*
* This code was written for assignment A3 CS3505 Spring 2022
* by Camille van Ginkel u0953582
*/

#include "Trie.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>

using std::cout;
using std::endl;
using std::invalid_argument;
using std::string;
using std::vector;

void putInVector(vector<string>& wordLines, const string &filename)
{
        std::ifstream source;
        source.open(filename);
        if(!source.good()) {
            throw invalid_argument("This file does not exist: " + filename);
        }
        string line;
        while (std::getline(source, line))
        {
            wordLines.push_back(line);
        }
}

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 3)
        {
            throw invalid_argument("This program requires its name plus two text filenames as command line arguements.  Incorrect number of arguements given");
        }
        string wordsFilename = argv[1];
        string queriesFilename = argv[2];

        vector<string> wordsFromFile;
        putInVector(wordsFromFile, wordsFilename);
        vector<string> queriesFromFile; 
        putInVector(queriesFromFile, queriesFilename);

        //make Trie from words in first file
        Trie wordTrie;
        for (vector<string>::iterator t = wordsFromFile.begin(); t != wordsFromFile.end(); ++t) {  
            wordTrie.addAWord(*t);
        }

        //check if words from second file are in the Trie
        for (vector<string>::iterator t = queriesFromFile.begin(); t != queriesFromFile.end(); ++t) {  
            if(wordTrie.isAWord(*t) ) {
                cout << *t << " is found." << endl;
            }
            else{
                cout << *t << " is not found. Did you mean: " << endl;
                vector<string> prefixWords = wordTrie.allWordsStartingWithPrefix(*t); 
                if (!prefixWords.empty()) {
                    for (vector<string>::iterator iter = prefixWords.begin(); iter != prefixWords.end(); ++iter) {
                        cout << *iter << endl;
                    }
                }
                else {
                    cout << "No alternatives found." << endl;
                }
            }
        }
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return -1;
    }
}
