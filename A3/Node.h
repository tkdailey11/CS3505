#ifndef Node_h
#define Node_h

/*
 * Created by Tyler Dailey, University of Utah, 9/13/16
 * Assignment 3, CS 3505
 *
 * This class represents a Node in a Trie. It holds a bool marker
 * that states if the path down to the Node is a word, and it holds
 * an array of Node* of length 26.
 */
class Node{

    Node* node_[26];
    bool isWord_;

public:

    Node();

    Node(const Node&);

    Node& operator=(Node);

    ~Node();

    bool getIsWord();
    void setIsWord(bool b);

    char* getKey();
    void setKey(char*);

    Node **getArray();

    void addToArray(int);

};

#endif
