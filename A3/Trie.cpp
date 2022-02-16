/*
* This code was written for assignment A3 CS3505 Spring 2022
* by Camille van Ginkel u0953582
*/

#include "Trie.h"
#include "Node.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

    Trie::Trie() {
        origin = Node();
    }
    
    Trie::Trie(string text) {
        this->addAWord(text);
    }
    
    /* A method addAWord that accepts a std::string and returns void. The word passed into the method 
    should be added to the Trie object. Duplicate adds should not change the Trie. You may assume that 
    the word is only made up of lower-case characters from a-z.
    */
    void Trie::addAWord(string word){
        origin.insertWord(word, 0);
    }

    /* A method isAWord that accepts a std::string and returns bool. The argument is a string assumed 
    to be made up of characters 'a'-'z'. If the word is found in the Trie, the method should return true, 
    otherwise return false.  A Trie should report that an empty string is not in the Trie.
    */
    bool Trie::isAWord(string word){
        return origin.isAWord(word, 0);
    }
    
    /* A method allWordsStartingWithPrefix that accepts a std::string and returns a vector<std::string> 
    *that contains all the words in the Trie that start with the passed in argument prefix string. If 
    *the prefix is a word, that should be included. An empty prefix should return all words in the Trie.
    */
    vector<string> Trie::allWordsStartingWithPrefix(string word) {
        vector<string> bucket;
        origin.getPrefixWords(bucket, word, 0);
        return bucket;
    }

    /*
    * Method to help visualize while debugging
    */
    void Trie::printTrie(string spacing){
        origin.printTree(spacing);
    }