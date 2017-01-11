#ifndef _BST_H_
#define _BST_H_

class Node
{
private:
    char    key;
    int     value;
    Node*   leftChild;
    Node*   rightChild;
    int     totalNodesInSubtree;

public:
    Node(char key, int value, int totalNodesInSubtree);
    ~Node();

    int     getTotalNodesInSubtree();
    void    setTotalNodesInSubtree(int totalNodesInSubtree);
    Node*   getLeftChild();
    Node*   getRightChild();
    void    setLeftChild(Node* leftChild);
    void    setRightChild(Node* leftChild);

    char    getKey();
    void    setKey(char key);
    void    setValue(int value);
    int     getValue();
};

class BST
{
private:
    Node* root;

    int     getSize(Node* node);
    int     getValue(Node* node, char key);
    Node*   putValueInBST(Node* node, char key, int val);

public:
    BST();
    ~BST();
    int getSize();
    int getValue(char key);
    void putValueInBST(char key, int val);
};

#endif // _BST_H_
