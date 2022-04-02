#include <iostream>
#include "Node.h"

void printAllElements(const std::shared_ptr<Node> root)
{
	printNodes(root);
}

void printNodes(const std::shared_ptr<Node> node)
{
	std::cout << node->val << std::endl;
	if(node->left)
		printNodes(node->left);
	if(node->right)
		printNodes(node->right);
}

bool checkIfPresent(const int value, const std::shared_ptr<Node> root)
{
	std::shared_ptr<Node> curElement = root;
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

bool addElement(const int value, std::shared_ptr<Node> root)
{
	std::shared_ptr<Node> curElement = root;
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
				curElement->right = std::shared_ptr<Node>(new Node);
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
				curElement->left = std::shared_ptr<Node>(new Node);
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

std::shared_ptr<Node> mostLeftNode(std::shared_ptr<Node> node)
{
	std::shared_ptr<Node> curElement = node;
	while (curElement && curElement->left)
		curElement = curElement->left;
	return curElement;
}

std::shared_ptr<Node> removeElement(const int value, std::shared_ptr<Node> root)
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
			std::shared_ptr<Node> temp = root->right;
			return temp;
		}
		else if(!root->right)
		{
			std::shared_ptr<Node> temp = root->left;
			return temp;
		}
		std::shared_ptr<Node> temp = mostLeftNode(root->right);
		root->val = temp->val;
		root->right = removeElement(root->val, root->right);
	}
	return root;
}

void removeTree(std::shared_ptr<Node> root)
{
	removeNodes(root);
}

void removeNodes(std::shared_ptr<Node> node)
{
	if(node->left)
		removeNodes(node->left);
	if(node->right)
		removeNodes(node->right);
	node->left = nullptr;
	node->right = nullptr;
	node = nullptr;
	
}

std::shared_ptr<Node> initRoot(const int value)
{
	std::shared_ptr<Node> root = std::shared_ptr<Node>(new Node);
	root->val = value;
	root->left = nullptr;
	root->right = nullptr;
	return root;
}
