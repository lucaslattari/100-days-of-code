#ifndef _BST_H_
#define _BST_H_

class Node
{
private:
    const char* key;
    int         value;
    Node*       leftChild;
    Node*       rightChild;
    int         totalNodesInSubtree;

public:
    Node(const char* key, int value, int totalNodesInSubtree);
    ~Node();

    int         getTotalNodesInSubtree();
    void        setTotalNodesInSubtree(int totalNodesInSubtree);
    Node*       getLeftChild();
    Node*       getRightChild();
    void        setLeftChild(Node* leftChild);
    void        setRightChild(Node* leftChild);

    const char* getKey();
    void        setKey(const char* key);
    void        setValue(int value);
    int         getValue();
};

class BST
{
private:
    Node*   root;

    int         getSize(Node* node);
    int         getValue(Node* node, const char* key);
    Node*       putValueInBST(Node* node, const char*, int val);
    void        deleteNode(Node* node);
    Node*       getNodeOfMinimumKey(Node* node);
    Node*       getNodeOfMaximumKey(Node* node);
    Node*       getKeyOfFloorNode(Node* node, const char* key);
    Node*       getKeyOfCeilingNode(Node* node, const char* key);
    Node*       getKeyByRank(Node* node, int _rank);
    int         getRankByKey(Node* node, const char* key);
    Node*       deleteNode(Node* node, const char* key);
    Node*       deleteMinNode(Node* node);
    void        printNode(Node* node);

public:
    BST();
    ~BST();
    int         getSize();
    int         getValue(const char* key);
    void        putValueInBST(const char* key, int val);
    int         getValueOfMinimumKey();
    int         getValueOfMaximumKey();
    const char* getKeyOfFloorNode(const char* key);
    const char* getKeyOfCeilingNode(const char* key);
    const char* getKeyByRank(int _rank);
    int         getRankByKey(const char* key);
    void        deleteNode(const char* key);
    void        printTree();
};

#endif // _BST_H_
