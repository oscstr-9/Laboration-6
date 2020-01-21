#include "Node.h"

Node::Node(int dataIn) {
	data = dataIn;
}

int Node::getData() {
	return data;
}

void Node::setData(int newData) {
	data = newData;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node *newNext) {
	next = newNext;
}

Node* Node::getPrev() {
	return prev;
}

void Node::setPrev(Node *newPrev) {
	prev = newPrev;
}