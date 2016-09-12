#include "Node.h"
#include "Trie.h"
#include <iostream>

Trie::Trie(){

}

Trie::Trie(const Trie& other){
    Node n(*other.root_);
    root_ = &n;
}


Trie& Trie::operator=(Trie other){
    std::swap(root_, other.root_);
    return *this;
}

void Trie::addWord(std::string s){

    Node* nextNode = root_;

    for(std::size_t i = 0; i < s.length(); i++){
        //char c = s[i];

        std::cout << s[i] << std::endl;

        int index = s[i]-'a';

        std::cout << index << std::endl;

        Node* n = new Node();

        Node** arr = nextNode->getArray();

        std::cout << sizeof(arr) << std::endl;

        nextNode = arr[index];

        if(nextNode == nullptr)
            nextNode = n;
    }

}

bool Trie::isWord(std::string s){
    return false;
}

std::vector<std::string> Trie::allWordsWithPrefix(std::string s){
    std::vector<std::string> test;
    return test;
}
