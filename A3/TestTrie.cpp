#include "Trie.h"
#include <iostream>
#include <string>

int main(){
    std::string s = "hello";
    std::string x = "not";

    Trie t;

    t.addWord(s);

    bool isWord1 = t.isWord(s);
    std::cout << isWord1 << std::endl;
    isWord1 = t.isWord(x);
    std::cout << isWord1 << std::endl;

    return 0;
}
