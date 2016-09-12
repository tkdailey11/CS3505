#ifndef Node_h
#define Node_h

#include <vector>

class Node{

    Node **node_;
    bool isWord_;

public:

    Node();

    Node(const Node&);

    Node& operator=(Node);

    bool getIsWord();
    void setIsWord(bool b);

    char* getKey();
    void setKey(char*);

    Node *getArray(int);
    /*/
    void addToArray(Node*, int);
    */


};

#endif
