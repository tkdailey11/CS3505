#include "Node.h"
#include "Trie.h"

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
        char c = s[i];
        int index = c-'a';

        Node n(c);

        if(nextNode->getVector().at(index) == nullptr){
            nextNode->addToVector(&n, index);
            nextNode = &n;
        }
        else{
            nextNode = nextNode->getVector().at(index);
        }
    }

}

bool Trie::isWord(std::string s){
    return false;
}

std::vector<std::string> Trie::allWordsWithPrefix(std::string s){
    std::vector<std::string> test;
    return test;
}
