#include "Node.h"
#include <string>

Node::Node(){
    node_ = new Node*[26];
    isWord_ = false;
}

Node::Node(const Node& other){
    isWord_ = other.isWord_;

    for(std::size_t i = 0; i < 26; i++)
        node_[i] = other.node_[i];
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

Node **Node::getArray(){
    return node_;
}

void Node::addToArray(Node* other, int index){
    node_[index] = other;
}
