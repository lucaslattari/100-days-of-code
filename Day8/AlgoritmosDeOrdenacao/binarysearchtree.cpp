#include <stdio.h>
#include <cstdlib>
#include "binarysearchtree.h"

using namespace std;

Node::Node(char key, int value, int totalNodesInSubtree)
{
    this->key                    = key;
    this->value                  = value;
    this->totalNodesInSubtree    = totalNodesInSubtree;
}

Node::~Node()
{

}

int Node::getTotalNodesInSubtree()
{
    return totalNodesInSubtree;
}

void Node::setTotalNodesInSubtree(int totalNodesInSubtree)
{
    this->totalNodesInSubtree = totalNodesInSubtree;
}

char Node::getKey()
{
    return key;
}

void Node::setKey(char key)
{
    this->key = key;
}

Node*   Node::getLeftChild()
{
    return leftChild;
}

Node*   Node::getRightChild()
{
    return rightChild;
}

void Node::setLeftChild(Node* leftChild)
{
    this->leftChild = leftChild;
}

void Node::setRightChild(Node* rightChild)
{
    this->rightChild = rightChild;
}

void Node::setValue(int value)
{
    this->value = value;
}

int Node::getValue()
{
    return value;
}

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{

}

int BST::getSize(Node* node)
{
    if(root == nullptr)
        return 0;
    return root->getTotalNodesInSubtree();
}

int BST::getSize()
{
    return getSize(root);
}

int BST::getValue(Node* node, char key)
{
    if(node == nullptr)
    {
        printf("ERRO: Acesso a nodo vazio.\n");
        exit(1);
    }
    int comparedValue = key - node->getKey();

    if(comparedValue < 0)
        return getValue(node->getLeftChild(), key);
    else if(comparedValue > 0)
        return getValue(node->getRightChild(), key);
    return node->getValue();
}

int BST::getValue(char key)
{
    return getValue(root, key);
}

Node* BST::putValueInBST(Node* node, char key, int val)
{
    if(node == nullptr)
        return new Node(key, val, 1);

    int comparedValue = key - node->getKey();

    if(comparedValue < 0)
        node->setLeftChild(putValueInBST(node->getLeftChild(), key, val));
    else if(comparedValue > 0)
        node->setRightChild(putValueInBST(node->getRightChild(), key, val));

    node->setValue(val);
    node->setTotalNodesInSubtree(node->getLeftChild()->getTotalNodesInSubtree() + node->getRightChild()->getTotalNodesInSubtree() + 1);

    return node;
}

void BST::putValueInBST(char key, int val)
{
    root = putValueInBST(root, key, val);
}


