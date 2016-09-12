#include "Node.h"
#include <string>
#include <iostream>

Node::Node(){
    isWord_ = false;

    node_ = new Node*[26];

    for (std::size_t i = 0; i < 26; i++){
        node_[i] = nullptr;
        std::cout << i << std::endl;
    }

    for (std::size_t i = 0; i < 26; i++){
        std::cout << node_[i] << std::endl;
    }

}

Node::Node(const Node& other){
    isWord_ = other.isWord_;

    for(std::size_t i = 0; i < 26; i++)
        node_[i] = other.node_[i];
}

Node::~Node(){
    delete [] node_;
}

Node& Node::operator=(Node other){
    std::swap(isWord_, other.isWord_);
    std::swap(node_, other.node_);
    return *this;
}

bool Node::getIsWord(){
    return false;
}

void Node::setIsWord(bool b){
    isWord_ = b;
}


Node* Node::getArray(int index){
    return node_[index];
}


void Node::addToArray(Node* other, int index){
    node_[index] = other;
}
