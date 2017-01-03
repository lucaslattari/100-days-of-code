#ifndef _BST_H_
#define _BST_H_

class Node
{
private:
    int     key;
    int     value;
    Node*   left;
    Node*   right;

public:
    Node(int, int, int);
};

class BST
{
private:
    Node root;
};

#endif // _BST_H_
