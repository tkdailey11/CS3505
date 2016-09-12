#include "Node.h"
#include <string>

Node::Node(){
    std::string s = "root";
    key_ = (char*)s.c_str();
    vect_.resize(26);
}

Node::Node(char c){
    key_ = &c;
    vect_.resize(26);
}

Node::Node(const Node& other){
    isWord_ = other.isWord_;
    key_ = other.key_;

    std::vector<Node*> n(other.vect_.size());

    vect_ = n;

    for(std::size_t i = 0; i < vect_.size(); i++)
        vect_.at(i) = other.vect_.at(i);
}


Node& Node::operator=(Node other){
    std::swap(isWord_, other.isWord_);
    std::swap(vect_, other.vect_);
    std::swap(key_, other.key_);
    return *this;
}

bool Node::getIsWord(){
    return false;
}

void Node::setIsWord(bool b){
    isWord_ = b;
}

char* Node::getKey(){
    return key_;
}

void Node::setKey(char* c){
    key_ = c;
}

std::vector<Node*> Node::getVector(){
    return vect_;
}

void Node::addToVector(Node* other, int index){
    vect_.at(index) = other;
}
