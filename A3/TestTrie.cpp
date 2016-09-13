#include "Trie.h"
#include <iostream>
#include <string>
#include "fstream"

int main(){
    std::string s = "hello";
    std::string x = "not";

    Trie t;

    t.addWord(s);

    //Check to see if the word was added correctly.
    if(t.isWord(s)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Failure" << std::endl;
    }

    //Check to see if a word that is not in the Trie is reported as false.
    if(!t.isWord(x)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Failure" << std::endl;
    }

    //Check to see if an empty string is reported as false.
    if(!t.isWord("")){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Failure" << std::endl;
    }

    std::ifstream file;
    file.open("dictionary.txt");
    if (!file.is_open())
        return -1;

    std::string word;
    while (file >> word){
        t.addWord(word);
    }
    file.close();

    bool allWordsAdded = true;

    file.open("dictionary.txt");
    if(!file.is_open()){
        return -1;
    }

    while(file >> word){
        if(!t.isWord(word)){
            allWordsAdded = false;
        }
    }

    if(allWordsAdded){
        std::cout << "Success Adding Dictionary." << std::endl;
    }
    else{
        std::cout << "Failure Adding Dictionary." << std::endl;
    }

    std::vector<std::string> results = t.allWordsWithPrefix("pac");

    std::cout << "Vector Size: " << results.size() << std::endl;

    for(std::size_t i = 0; i < results.size(); i ++){
        std::cout << results.at(i) << std::endl;
    }

    return 0;
}
