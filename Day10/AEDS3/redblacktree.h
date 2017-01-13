#ifndef _RBT_H_
#define _RBT_H_

#include "binarysearchtree.h"

const bool RED      = true;
const bool BLACK    = false;

class NodeRBT : public Node
{
private:
    bool        colorOfParentLink;
    NodeRBT*    leftChild;
    NodeRBT*    rightChild;

public:
    NodeRBT(const char* key, int value, int totalNodesInSubtree, bool colorOfParentLink);
    ~NodeRBT();

    NodeRBT*    getLeftChild();
    NodeRBT*    getRightChild();
    void        setLeftChild(NodeRBT* leftChild);
    void        setRightChild(NodeRBT* rightChild);

    void        setColor(bool colorOfParentLink);
    bool        getColor();
};

class RedBlackTree : public BinarySearchTree
{
private:
    NodeRBT*    root;
    NodeRBT*    putValueInRBT(NodeRBT* node, const char* key, int val);
    void        printNode(NodeRBT* node);
    void        checkConditionOfBothRedChildren(NodeRBT* node);

public:
    RedBlackTree();
    ~RedBlackTree();
    void        flipColorsOfNode(NodeRBT* node);
    bool        checkIfParentLinkIsRed(NodeRBT* node);
    NodeRBT*    rotateLeft(NodeRBT* rotatedNode);
    NodeRBT*    rotateRight(NodeRBT* rotatedNode);
    void        putValueInRBT(const char* key, int val);
    void        printTree();
};

#endif
