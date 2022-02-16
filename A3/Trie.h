/*
* This code was written for assignment A3 CS3505 Spring 2022
* by Camille van Ginkel u0953582
*/

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include "Node.h"

using std::vector;
using std::string;
class Trie {
private:
    Node origin;
public:
    //A default constructor
    Trie();
    Trie(string text); 

    //A method addAWord that accepts a std::string and returns void. The word passed into the method should be added to the Trie object. Duplicate adds should not change the Trie. You may assume that the word is only made up of lower-case characters from a-z.
    void addAWord(string word);
    //A method isAWord that accepts a std::string and returns bool. The argument is a string assumed to be made up of characters 'a'-'z'. If the word is found in the Trie, the method should return true, otherwise return false.  A Trie should report that an empty string is not in the Trie.
    bool isAWord(string word);
    //A method allWordsStartingWithPrefix that accepts a std::string and returns a vector<std::string> that contains all the words in the Trie that start with the passed in argument prefix string. If the prefix is a word, that should be included. An empty prefix should return all words in the Trie.
    vector<string> allWordsStartingWithPrefix(string word);

    void printTrie(string spacing);
};

#endif 


