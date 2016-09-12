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
        //char c = s[i];

        int index = s[i]-'a';

        std::cout << "index is: " << index << std::endl;

        Node* n = new Node();

        std::cout << "Creates new Node*" << std::endl;

        //nextNode->getArray()[index];

        //std::cout << "Size of array (in bytes): " << sizeof(arr) << std::endl;

        nextNode = nextNode->getArray(index);

        std::cout << "Success accessing the array " << std::endl;

        if(nextNode == nullptr)
            nextNode->addToArray(n, index);
    }

    nextNode->setIsWord(true);

}

bool Trie::isWord(std::string s){

    Node* nextNode = root_;

    for(std::size_t i = 0; i < s.length(); i++){

        int index = s[i]-'a';

        nextNode = nextNode->getArray(index);

        if(nextNode == nullptr)
            return false;
    }

    return true;
}

std::vector<std::string> Trie::allWordsWithPrefix(std::string s){
    std::vector<std::string> test;
    return test;
}
