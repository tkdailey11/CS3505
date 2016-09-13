#ifndef Trie_h
#define Trie_h

#include "Node.h"
#include <string>
#include <vector>

class Trie{

private:
    Node* root_;

    std::vector<std::string> recurSearch(Node*, std::string);

public:
    Trie();

    ~Trie();

    Trie(const Trie&);

    Trie& operator=(Trie);

    void addWord(std::string);

    bool isWord(std::string);

    std::vector<std::string> allWordsWithPrefix(std::string);
};

#endif
