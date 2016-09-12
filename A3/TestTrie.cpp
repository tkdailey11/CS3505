#include "Trie.h"
#include <iostream>
#include <string>

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

    return 0;
}
