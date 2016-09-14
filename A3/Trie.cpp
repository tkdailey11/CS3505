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

    bool b = true;
    nextNode->setIsWord(b);
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

        nextNode = arr[index];
    }

    return nextNode->getIsWord();
}

std::vector<std::string> Trie::allWordsWithPrefix(std::string prefix){

    Node* endOfWord = root_;

    //Advance down the Trie to the Node of the last character in prefix.
    for(std::size_t i = 0; i < prefix.length(); i++){
        Node** arr = endOfWord->getArray();
        int index = prefix[i]-'a';
        endOfWord = arr[index];
    }

    results_.clear();
    recurSearch(endOfWord, prefix);

    return results_;
}

void Trie::recurSearch(Node* parentNode, std::string word){

    std::vector<std::string> test;

    Node** arr = parentNode->getArray();
    for(int i = 0; i < 26; i++){
        if(arr[i] != nullptr){
            char c = 'a'+i;
            std::string temp = word + c;
            //It is actually traversing through the Trie correctly, now it just needs
            //to add them to some vector to return...
            if(isWord(temp)){
                results_.push_back(temp);
            }
            //results_.push_back(word);
            recurSearch(arr[i], temp);
        }
    }
}
