#pragma once
#include "Node.h"

class DoubleLinkedList
{
	Node *head;
	Node *tail;
	int sizeOfList = 0;
	Node *targetNode;
public:
	DoubleLinkedList(Node *headIn, Node *tailIn);
	bool add(Node *data, int pos);
	bool remove(int pos);
	bool replace(Node *oldNode, Node *newNode);
	int search(Node *data);
	Node* nodeAt(int pos);
	void displayForward();
	void displayBackward();
	int size();
};

