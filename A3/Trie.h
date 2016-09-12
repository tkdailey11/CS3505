#ifndef Trie_h
#define Trie_h

#include "Node.h"
#include <string>

class Trie{

    Node* root_;

public:
    Trie();

    //~Trie();

    Trie(const Trie&);

    Trie& operator=(Trie);

    void addWord(std::string);

    bool isWord(std::string);

    std::vector<std::string> allWordsWithPrefix(std::string);
};

#endif
