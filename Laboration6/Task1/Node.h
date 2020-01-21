#pragma once
class Node
{
	int data;
	Node *next;
	Node *prev;
public:
	Node(int dataIn);
	int getData();
	void setData(int newData);
	Node *getNext();
	void setNext(Node *newNext);
	Node* getPrev();
	void setPrev(Node *newPrev);
};

