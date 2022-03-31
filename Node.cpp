#include <iostream>
#include "Node.h"

void printAllElements(const Node *root)
{
    printNodes(root);
}

void printNodes(const Node *node)
{
    std::cout << node->val << std::endl;
    if(node->left)
        printNodes(node->left);
    if(node->right)
        printNodes(node->right);
}

bool checkIfPresent(const int value, const Node *root)
{
    const Node *curElement = root;
    while(true) 
    {
        if(!curElement)
        {
            std::cout << "Value " << value << " doesn't exist" << std::endl;
            return false;
        }
        
        if(curElement->val == value)
        {
            std::cout << "Value " << value << " exists" << std::endl;
            return true;
        }

        if(curElement->right && value > curElement->val)
        {
            curElement = curElement->right;
            continue;
        }

        if(curElement->left && value < curElement->val)
        {
            curElement = curElement->left;
            continue;
        }
        
        else
        {
            std::cout << "Value " << value << " doesn't exist" << std::endl;
            return false;
        }
    }
}

bool addElement(const int value, Node *root)
{
    Node *curElement = root;
    while(true) 
    {
        if(curElement->val == value)
        {
            std::cout << "Value already exists" << std::endl;
            return false;
        }

        if(value > curElement->val)
        {
            if(!curElement->right)
            {
                curElement->right = new Node;
                curElement->right->val = value;
                curElement->right->left = nullptr;
                curElement->right->right= nullptr;
                return true;
            }
            else
                curElement = curElement->right;
        }

        if(value < curElement->val)
        {
            if(!curElement->left)
            {
                curElement->left = new Node;
                curElement->left->val = value;
                curElement->left->left = nullptr;
                curElement->left->right = nullptr;
                return true;
            }
            else
                curElement = curElement->left;
        }

    }
}

Node* mostLeftNode(Node *node)
{
    Node* curElement = node;
    while (curElement && curElement->left)
        curElement = curElement->left;
    return curElement;
}

Node* removeElement(const int value, Node *root)
{
    if(!root)
        return root;
    if(value < root->val)
        root->left = removeElement(value, root->left);
    else if(value > root->val)
        root->right = removeElement(value, root->right);
    else {
        if(!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = mostLeftNode(root->right);
        root->val = temp->val;
        root->right = removeElement(root->val, root->right);
    }
    return root;
}

void removeTree(Node *root)
{
    removeNodes(root);
}

void removeNodes(Node *node)
{
    if(node->left)
        removeNodes(node->left);
    if(node->right)
        removeNodes(node->right);
    node->left = nullptr;
    node->right = nullptr;
    delete node;
    node = nullptr;
    
}

Node * init_root(const int value)
{
    Node *root = new Node;
    root->val = value;
    root->left = nullptr;
    root->right = nullptr;
    return root;
}

int main()
{
    Node *root = init_root(2023);
    addElement(2020, root);
    addElement(2022, root);
    addElement(2025, root);
    addElement(2026, root);
    addElement(2027, root);
    addElement(2019, root);
    addElement(2021, root);
    addElement(2029, root);
    checkIfPresent(2026, root);
    removeElement(2026, root);
    checkIfPresent(2026, root);
    printAllElements(root);
    removeTree(root);
    return 0;
}
