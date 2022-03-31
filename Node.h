#pragma once

struct Node
{
    int val;
    Node *left;
    Node *right;
};

void printAllElements(const Node *root);

void printNodes(const Node *node);

bool checkIfPresent(const int value, const Node *root);

bool addElement(const int value, Node *root);

Node* mostLeftNode(Node *node);

Node* removeElement(const int value, Node *root);

void removeTree(Node *root);

void removeNodes(Node *node);