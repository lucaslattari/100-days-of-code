#include <stdio.h>
#include <cstdlib>
#include "binarysearchtree.h"

using namespace std;

Node::Node(const char* key, int value, int totalNodesInSubtree)
{
    this->key                   = key;
    this->value                 = value;
    this->totalNodesInSubtree   = totalNodesInSubtree;

    this->leftChild             = nullptr;
    this->rightChild            = nullptr;
}

Node::~Node()
{
}

void BST::deleteNode(Node* node)
{
    if(node == nullptr)
        return;
    else if(node->getTotalNodesInSubtree() == 1)
    {
        delete(node);
        return;
    }else
    {
        deleteNode(node->getLeftChild());
        deleteNode(node->getRightChild());
        delete(node);
    }
}

int Node::getTotalNodesInSubtree()
{
    return totalNodesInSubtree;
}

void Node::setTotalNodesInSubtree(int totalNodesInSubtree)
{
    this->totalNodesInSubtree = totalNodesInSubtree;
}

const char* Node::getKey()
{
    return key;
}

void Node::setKey(const char* key)
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
    deleteNode(root);
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

int BST::getValue(Node* node, const char* key)
{
    if(node == nullptr)
    {
        printf("ERRO: Acesso a nodo vazio.\n");
        exit(1);
    }
    int comparedValue = *key - *(node->getKey)();

    if(comparedValue < 0)
        return getValue(node->getLeftChild(), key);
    else if(comparedValue > 0)
        return getValue(node->getRightChild(), key);
    return node->getValue();
}

int BST::getValue(const char* key)
{
    return getValue(root, key);
}

Node* BST::putValueInBST(Node* node, const char* key, int val)
{
    if(node == nullptr)
        return new Node(key, val, 1);

    int comparedValue = *key - *(node->getKey)();

    if(comparedValue < 0)
        node->setLeftChild(putValueInBST(node->getLeftChild(), key, val));
    else if(comparedValue > 0)
        node->setRightChild(putValueInBST(node->getRightChild(), key, val));
    else
        printf("WARNING: Tentou inserir chave ja existente. Insercao ignorada.\n");

    int totalNodesInSubtreeOfThisNewNode = 0;
    if(node->getLeftChild() != nullptr)
        totalNodesInSubtreeOfThisNewNode += node->getLeftChild()->getTotalNodesInSubtree();
    if(node->getRightChild() != nullptr)
        totalNodesInSubtreeOfThisNewNode += node->getRightChild()->getTotalNodesInSubtree();
    node->setTotalNodesInSubtree(totalNodesInSubtreeOfThisNewNode + 1);

    return node;
}

void BST::putValueInBST(const char* key, int val)
{
    root = putValueInBST(root, key, val);
}

int BST::getValueOfMinimumKey()
{
    return getNodeOfMinimumKey(root)->getValue();
}

Node* BST::getNodeOfMinimumKey(Node* node)
{
    if(node->getLeftChild() == nullptr)
        return node;
    return getNodeOfMinimumKey(node->getLeftChild());
}

int BST::getValueOfMaximumKey()
{
    return getNodeOfMaximumKey(root)->getValue();
}

Node* BST::getNodeOfMaximumKey(Node* node)
{
    if(node->getRightChild() == nullptr)
        return node;
    return getNodeOfMaximumKey(node->getRightChild());
}

Node* BST::getKeyOfFloorNode(Node* node, const char* key)
{
    if(node == nullptr)
        return nullptr;

    int comparedValue = *key - *(node->getKey)();
    if(comparedValue == 0)
        return node;
    else if (comparedValue < 0)
        return getKeyOfFloorNode(node->getLeftChild(), key);

    Node* t = getKeyOfFloorNode(node->getRightChild(), key);
    if(t != nullptr)
        return t;
    return node;
}

const char* BST::getKeyOfFloorNode(const char* key)
{
    Node* node = getKeyOfFloorNode(root, key);
    if(node == nullptr)
        return nullptr;
    return node->getKey();
}

Node* BST::getKeyOfCeilingNode(Node* node, const char* key)
{
    if(node == nullptr)
        return nullptr;

    int comparedValue = *key - *(node->getKey)();
    if(comparedValue == 0)
        return node;
    else if (comparedValue > 0)
        return getKeyOfCeilingNode(node->getRightChild(), key);

    Node* t = getKeyOfCeilingNode(node->getLeftChild(), key);
    if(t != nullptr)
        return t;
    return node;
}

const char* BST::getKeyOfCeilingNode(const char* key)
{
    Node* node = getKeyOfCeilingNode(root, key);
    if(node == nullptr)
        return nullptr;
    return node->getKey();
}

Node* BST::getKeyByRank(Node* node, int _rank)
{
    if(node == nullptr)
        return nullptr;
    int totalNodesOfLeftSubtree = 0;
    if(node->getLeftChild() != nullptr)
        totalNodesOfLeftSubtree = node->getLeftChild()->getTotalNodesInSubtree();

    if(totalNodesOfLeftSubtree > _rank)
        return getKeyByRank(node->getLeftChild(), _rank);
    else if(totalNodesOfLeftSubtree < _rank)
        return getKeyByRank(node->getRightChild(), _rank - totalNodesOfLeftSubtree - 1);
    return node;
}

const char* BST::getKeyByRank(int _rank)
{
    return getKeyByRank(root, _rank)->getKey();
}

int BST::getRankByKey(Node* node, const char* key)
{
    if(node == nullptr)
        return 0;
    int comparedValue = *key - *(node->getKey)();
    if(comparedValue < 0)
        return getRankByKey(node, key);
    else if(comparedValue > 0)
    {
        int totalNodesOfLeftSubtree = 1;
        if(node->getLeftChild() != nullptr)
            totalNodesOfLeftSubtree += node->getLeftChild()->getTotalNodesInSubtree();
        return totalNodesOfLeftSubtree + getRankByKey(node->getRightChild(), key);
    }else
    {
        if(node->getLeftChild() != nullptr)
            return node->getLeftChild()->getTotalNodesInSubtree();
        return 0;
    }
}

int BST::getRankByKey(const char* key)
{
    return getRankByKey(root, key);
}

Node* BST::deleteMinNode(Node* node)
{
    if(node->getLeftChild() == nullptr)
        return node->getRightChild();
    node->setLeftChild(deleteMinNode(node->getLeftChild()));

    int totalNodesAfterDeletion = 1;
    if(node->getLeftChild() != nullptr)
        totalNodesAfterDeletion += node->getLeftChild()->getTotalNodesInSubtree();
    if(node->getRightChild() != nullptr)
        totalNodesAfterDeletion += node->getRightChild()->getTotalNodesInSubtree();
    node->setTotalNodesInSubtree(totalNodesAfterDeletion);

    return node;
}

Node* BST::deleteNode(Node* node, const char* key)
{
    if(node == nullptr)
        return nullptr;

    int comparedValue = *key - *(node->getKey)();
    if(comparedValue < 0)
        node->setLeftChild(deleteNode(node->getLeftChild(), key));
    else if(comparedValue > 0)
        node->setRightChild(deleteNode(node->getRightChild(), key));
    else
    {
        if(node->getRightChild() == nullptr)
            return node->getLeftChild();
        if(node->getLeftChild() == nullptr)
            return node->getRightChild();

        Node* referenceToDeletedNode = node;
        node = getNodeOfMinimumKey(referenceToDeletedNode->getRightChild()); //get sucessor of node
        node->setRightChild(deleteMinNode(referenceToDeletedNode->getRightChild()));
        node->setLeftChild(referenceToDeletedNode->getLeftChild());
    }

    int totalNodesAfterDeletion = 1;
    if(node->getLeftChild() != nullptr)
        totalNodesAfterDeletion += node->getLeftChild()->getTotalNodesInSubtree();
    if(node->getRightChild() != nullptr)
        totalNodesAfterDeletion += node->getRightChild()->getTotalNodesInSubtree();
    node->setTotalNodesInSubtree(totalNodesAfterDeletion);

    return node;
}

void BST::deleteNode(const char* key)
{
    root = deleteNode(root, key);
}

void BST::printNode(Node* node)
{
    if(node == nullptr)
        return;

    printf("Key: %c\n", *(node->getKey()));
    printNode(node->getLeftChild());
    printNode(node->getRightChild());
}

void BST::printTree()
{
    printNode(root);
}
