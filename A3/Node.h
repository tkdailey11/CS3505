#ifndef Node_h
#define Node_h


class Node{

    Node **node_;
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
