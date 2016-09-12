#ifndef Node_h
#define Node_h

#include <vector>

class Node{

    std::vector<Node*> vect_;
    bool isWord_ = false;
    char* key_;

public:

    Node();

    Node(char);

    Node(const Node&);

    Node& operator=(Node);

    bool getIsWord();
    void setIsWord(bool b);

    char* getKey();
    void setKey(char*);

    std::vector<Node*> getVector();
    void addToVector(Node*, int);


};

#endif
