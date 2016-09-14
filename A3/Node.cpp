/*
 * Created by Tyler Dailey, University of Utah, 9/13/16
 * Assignment 3, CS 3505
 *
 */

#include "Node.h"
#include <string>
#include <iostream>

//Default Constructor
Node::Node(){
    isWord_ = false;

    for (std::size_t i = 0; i < 26; i++){
        node_[i] = nullptr;
    }
}

//Copy Constructor
Node::Node(const Node& other){
    isWord_ = other.isWord_;

    for(std::size_t i = 0; i < 26; i++)
        node_[i] = other.node_[i];
}

//Destructor
Node::~Node(){
    delete [] node_;
}

//Override = operator
Node& Node::operator=(Node other){
    std::swap(isWord_, other.isWord_);
    std::swap(node_, other.node_);
    return *this;
}

bool Node::getIsWord(){
    return isWord_;
}

void Node::setIsWord(bool b){
    isWord_ = b;
}


Node** Node::getArray(){
    return node_;
}

//Add a new Node to the array at the index provided.
void Node::addToArray(int index){
    node_[index] = new Node();
}
