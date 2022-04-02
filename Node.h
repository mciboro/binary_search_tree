#pragma once

#include <memory>

struct Node
{
	int val;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
};

void printAllElements(const std::shared_ptr<Node> root);

void printNodes(const std::shared_ptr<Node> node);

bool checkIfPresent(const int value, const std::shared_ptr<Node> root);

bool addElement(const int value, std::shared_ptr<Node> root);

std::shared_ptr<Node> mostLeftNode(std::shared_ptr<Node> node);

std::shared_ptr<Node> removeElement(const int value, std::shared_ptr<Node> root);

void removeTree(std::shared_ptr<Node> root);

void removeNodes(std::shared_ptr<Node> node);

std::shared_ptr<Node> initRoot(const int value);
