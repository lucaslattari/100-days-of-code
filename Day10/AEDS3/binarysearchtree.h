#ifndef _BST_H_
#define _BST_H_

class Node
{
private:
    Node*       leftChild;
    Node*       rightChild;

protected:
    const char* key;
    int         value;
    int         totalNodesInSubtree;

public:
    Node(const char* key, int value, int totalNodesInSubtree);
    ~Node();

    int         getTotalNodesInSubtree();
    void        setTotalNodesInSubtree(int totalNodesInSubtree);
    Node*       getLeftChild();
    Node*       getRightChild();
    void        setLeftChild(Node* leftChild);
    void        setRightChild(Node* rightChild);

    const char* getKey();
    void        setKey(const char* key);
    void        setValue(int value);
    int         getValue();
};

class BinarySearchTree
{
private:
    Node*       root;
    Node*       putValueInBST(Node* node, const char* key, int val);
    Node*       deleteMinNode(Node* node);
    Node*       deleteNode(Node* node, const char* key);
    void        deleteNode(Node* node);

protected:
    int         getSize(Node* node);
    int         getValue(Node* node, const char* key);
    Node*       getNodeOfMinimumKey(Node* node);
    Node*       getNodeOfMaximumKey(Node* node);
    Node*       getKeyOfFloorNode(Node* node, const char* key);
    Node*       getKeyOfCeilingNode(Node* node, const char* key);
    Node*       getKeyByRank(Node* node, int _rank);
    int         getRankByKey(Node* node, const char* key);
    void        printNode(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();
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
