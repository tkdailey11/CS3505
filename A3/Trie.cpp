#include "Node.h"
#include "Trie.h"
#include <iostream>

Trie::Trie(){
    root_ = new Node;
}

Trie::Trie(const Trie& other){
    Node n(*other.root_);
    root_ = &n;
}

Trie::~Trie(){
    delete root_;
}

Trie& Trie::operator=(Trie other){
    std::swap(root_, other.root_);
    return *this;
}

void Trie::addWord(std::string s){

    Node* nextNode = root_;

    for(std::size_t i = 0; i < s.length(); i++){

        int index = s[i]-'a';

        Node** arr = nextNode->getArray();

        if(arr[index] == nullptr){
            nextNode->addToArray(index);
        }

        nextNode = nextNode->getArray()[index];
    }

    nextNode->setIsWord(true);

}

bool Trie::isWord(std::string s){

    if(s == ""){
        return false;
    }

    Node* nextNode = root_;

    for(std::size_t i = 0; i < s.length(); i++){

        int index = s[i]-'a';

        Node** arr = nextNode->getArray();

        if(arr[index] == nullptr){
            return false;
        }

        nextNode = nextNode->getArray()[index];
    }

    return true;
}

std::vector<std::string> Trie::allWordsWithPrefix(std::string s){
    std::vector<std::string> test;
    return test;
}
