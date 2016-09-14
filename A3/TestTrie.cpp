/*
 * Created by Tyler Dailey, University of Utah, 9/13/16
 * Assignment 3, CS 3505
 *
 * Provides code to test the Trie class. Takes in two strings from the command
 * line which specify files where the first one is the words to be added to
 * the Trie, and the second file is a list of queries for the Trie.
 */

#include "Trie.h"
#include <iostream>
#include <string>
#include "fstream"

int main(int argc, char* argv[]){

    //If the correct number of input strings were not provided,
    //report this, and terminate.
    if(argc != 3){
        std::cout << "Invalid Number of Arguments..." << std::endl;
        return -1;
    }

    std::string filename1 = argv[1];
    std::string filename2 = argv[2];

    Trie t;

    //Open the first file and add all words to the Trie.
    std::ifstream file1;
    file1.open(filename1);;
    if (!file1.is_open())
        return -1;

    std::string word;

    //Read a word from the file into the word variable.
    while (file1 >> word){
        t.addWord(word);
    }
    file1.close();

    //Check to see if all of the words in the second file are in the Trie.
    std::ifstream file2;
    file2.open(filename2);
    if (!file2.is_open()){
        return -1;
    }

    //Read a word from the file into the word variable.
    while (file2 >> word){

        if(t.isWord(word)){
            std::cout << word << " is found" << std::endl;
        }
        else{

            std::vector<std::string> wordsList = t.allWordsWithPrefix(word);

            if(wordsList.size() == 0){
                std::cout << "   no alternatives found" << std::endl;
            }
            else{
                std::cout << word << " is not found, did you mean:" << std::endl;
                for(std::size_t i = 0; i < wordsList.size(); i++){
                    std::cout << "   " << wordsList.at(i) << std::endl;
                }
            }
        }

    }
    file2.close();

    return 0;
}
