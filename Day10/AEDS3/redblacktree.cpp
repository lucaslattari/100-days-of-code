#include <stdio.h>
#include "redblacktree.h"

using namespace std;

NodeRBT::NodeRBT(const char* key, int value, int totalNodesInSubtree, bool colorOfParentLink) : Node(key, value, totalNodesInSubtree), colorOfParentLink(colorOfParentLink)
{
    leftChild = nullptr;
    rightChild = nullptr;
}

NodeRBT::~NodeRBT()
{
}

void NodeRBT::setColor(bool colorOfParentLink)
{
    this->colorOfParentLink = colorOfParentLink;
}

bool NodeRBT::getColor()
{
    return colorOfParentLink;
}

NodeRBT* NodeRBT::getLeftChild()
{
    return leftChild;
}

NodeRBT* NodeRBT::getRightChild()
{
    return rightChild;
}

void NodeRBT::setLeftChild(NodeRBT* leftChild)
{
    this->leftChild = leftChild;
}

RedBlackTree::RedBlackTree()
{
    root = nullptr;
}

RedBlackTree::~RedBlackTree()
{
}

void NodeRBT::setRightChild(NodeRBT* rightChild)
{
    this->rightChild = rightChild;
}

bool RedBlackTree::checkIfParentLinkIsRed(NodeRBT* node)
{
    if(node == nullptr) return BLACK;
    return (node->getColor() == RED);
}

NodeRBT* RedBlackTree::rotateLeft(NodeRBT* rotatedNode)
{
    NodeRBT* newParentNode = rotatedNode->getRightChild();
    rotatedNode->setRightChild(newParentNode->getLeftChild());
    newParentNode->setLeftChild(rotatedNode);
    newParentNode->setColor(rotatedNode->getColor());
    rotatedNode->setColor(RED);
    newParentNode->setTotalNodesInSubtree(rotatedNode->getTotalNodesInSubtree());

    int totalNodesInSubtreeOfRotatedNode = 1;
    if(rotatedNode->getLeftChild() != nullptr)
        totalNodesInSubtreeOfRotatedNode += rotatedNode->getLeftChild()->getTotalNodesInSubtree();
    if(rotatedNode->getRightChild() != nullptr)
        totalNodesInSubtreeOfRotatedNode += rotatedNode->getRightChild()->getTotalNodesInSubtree();
    rotatedNode->setTotalNodesInSubtree(totalNodesInSubtreeOfRotatedNode);

    return newParentNode;
}

NodeRBT* RedBlackTree::rotateRight(NodeRBT* rotatedNode)
{
    NodeRBT* newParentNode = rotatedNode->getLeftChild();
    rotatedNode->setLeftChild(newParentNode->getRightChild());
    newParentNode->setRightChild(rotatedNode);
    newParentNode->setColor(rotatedNode->getColor());
    rotatedNode->setColor(RED);
    newParentNode->setTotalNodesInSubtree(rotatedNode->getTotalNodesInSubtree());

    int totalNodesInSubtreeOfRotatedNode = 1;
    if(rotatedNode->getLeftChild() != nullptr)
        totalNodesInSubtreeOfRotatedNode += rotatedNode->getLeftChild()->getTotalNodesInSubtree();
    if(rotatedNode->getRightChild() != nullptr)
        totalNodesInSubtreeOfRotatedNode += rotatedNode->getRightChild()->getTotalNodesInSubtree();
    rotatedNode->setTotalNodesInSubtree(totalNodesInSubtreeOfRotatedNode);

    return newParentNode;
}

void RedBlackTree::flipColorsOfNode(NodeRBT* node)
{
    node->setColor(RED);
    node->getLeftChild()->setColor(BLACK);
    node->getRightChild()->setColor(BLACK);
}

NodeRBT* RedBlackTree::putValueInRBT(NodeRBT* node, const char* key, int val)
{
    if(node == nullptr)
        return new NodeRBT(key, val, 1, RED);

    int comparedValue = *key - *(node->getKey());

    if(comparedValue < 0)
        node->setLeftChild(putValueInRBT(node->getLeftChild(), key, val));
    else if(comparedValue > 0)
        node->setRightChild(putValueInRBT(node->getRightChild(), key, val));
    else
        printf("WARNING: Tentou inserir chave ja existente. Insercao ignorada.\n");

    NodeRBT* rightChildOfNode    = node->getRightChild();
    NodeRBT* leftChildOfNode     = node->getLeftChild();

    if(checkIfParentLinkIsRed(rightChildOfNode) && !checkIfParentLinkIsRed(leftChildOfNode))
        node = rotateLeft(node);

    NodeRBT* leftOfLeftChildOfNode = nullptr;
    if(leftChildOfNode != nullptr)
        if(leftChildOfNode->getLeftChild() != nullptr)
            leftOfLeftChildOfNode = leftChildOfNode->getLeftChild();
    if(checkIfParentLinkIsRed(leftChildOfNode) && checkIfParentLinkIsRed(leftOfLeftChildOfNode))
        node = rotateRight(node);

    int totalNodesInSubtreeOfThisNewNode = 0;
    if(node->getLeftChild() != nullptr)
        totalNodesInSubtreeOfThisNewNode += node->getLeftChild()->getTotalNodesInSubtree();
    if(node->getRightChild() != nullptr)
        totalNodesInSubtreeOfThisNewNode += node->getRightChild()->getTotalNodesInSubtree();
    node->setTotalNodesInSubtree(totalNodesInSubtreeOfThisNewNode + 1);

    return node;
}

void RedBlackTree::checkConditionOfBothRedChildren(NodeRBT* node)
{
    NodeRBT* rightChildOfNode    = node->getRightChild();
    NodeRBT* leftChildOfNode     = node->getLeftChild();

    if(leftChildOfNode != nullptr)
        checkConditionOfBothRedChildren(leftChildOfNode);
    if(rightChildOfNode != nullptr)
        checkConditionOfBothRedChildren(rightChildOfNode);

    if(checkIfParentLinkIsRed(rightChildOfNode) && checkIfParentLinkIsRed(leftChildOfNode))
        flipColorsOfNode(node);
}

void RedBlackTree::putValueInRBT(const char* key, int val)
{
    root = putValueInRBT(root, key, val);
    root->setColor(BLACK);

    checkConditionOfBothRedChildren(root);
}

void RedBlackTree::printNode(NodeRBT* node)
{
    if(node == nullptr)
        return;

    printf("Key: %c\n", *(node->getKey()));
    if(node->getColor() == true)
        printf("Color: RED\n");
    else
        printf("Color: BLACK\n");

    if(node->getLeftChild() != nullptr)
        printf("Left child: %c\n", *(node->getLeftChild()->getKey()));
    else
        printf("Left child: None\n");

    if(node->getRightChild() != nullptr)
        printf("Right child: %c\n", *(node->getRightChild()->getKey()));
    else
        printf("Right child: None\n");

    printNode(node->getLeftChild());
    printNode(node->getRightChild());
}

void RedBlackTree::printTree()
{
    printNode(root);
    printf("\n");
}

