/*
 * Created by Tyler Dailey, University of Utah, 9/13/16
 * Assignment 3, CS 3505
 *
 */


#include "Node.h"
#include "Trie.h"
#include <iostream>

//Default Constructor
Trie::Trie(){
}

//Copy Constructor
Trie::Trie(const Trie& other){
    Node n(*other.root_);
    root_ = &n;
}

//Destructor
Trie::~Trie(){
    delete root_;
}

//Overload = Operator
Trie& Trie::operator=(Trie other){
    std::swap(root_, other.root_);
    return *this;
}

//Add the provided word to the Trie.
void Trie::addWord(std::string s){

    Node* nextNode = root_;

    for(std::size_t i = 0; i < s.length(); i++){

        int index = s[i]-'a';

        Node** arr = nextNode->getArray();

        //Add a new Node to the array of NextNode. If there isn't a nullptr
        //at arr[index] the substring up to this point is already in the Trie.
        if(arr[index] == nullptr){
            nextNode->addToArray(index);
        }

        nextNode = nextNode->getArray()[index];
    }

    nextNode->setIsWord(true);
}

//Return true if s is contained in the Trie.
bool Trie::isWord(std::string s){

    if(s == ""){
        return false;
    }

    Node* nextNode = root_;

    //Advance down the array to the Node the last 'letter' is pointing at.
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

//Return a vector containing all words that begin with the provided prefix.
std::vector<std::string> Trie::allWordsWithPrefix(std::string prefix){

    Node* endOfWord = root_;

    //Advance down the Trie to the Node of the last character in prefix.
    for(std::size_t i = 0; i < prefix.length(); i++){
        Node** arr = endOfWord->getArray();
        int index = prefix[i]-'a';
        endOfWord = arr[index];
        if(endOfWord == nullptr){
            results_.clear();
            return results_;
        }
    }

    results_.clear();
    if(endOfWord == nullptr){
        return results_;
    }
    recurSearch(endOfWord, prefix);

    return results_;
}

//Recursive method that searches all Nodes branching off of the provided parentNode,
//that begin with the provided word.
void Trie::recurSearch(Node* parentNode, std::string word){

    std::vector<std::string> test;

    Node** arr = parentNode->getArray();
    for(int i = 0; i < 26; i++){
        if(arr[i] != nullptr){
            char c = 'a'+i;
            std::string temp = word + c;
            if(isWord(temp)){
                results_.push_back(temp);
            }
            recurSearch(arr[i], temp);
        }
    }
}

std::vector<std::string> Trie::wordsWithWildcardPrefix(std::string prefix){
    std::vector<std::string> results;
    return results;
}
