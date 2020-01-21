#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList(Node* headIn, Node* tailIn) {
	head = headIn;
	tail = tailIn;
}

bool DoubleLinkedList::add(Node* data, int pos) {
	Node *targetNode = head;
	if (pos > sizeOfList || pos < 0 ) { // if out of index
		return false;
	}
	if (pos == 0 && pos == sizeOfList) { // if the only object in list
		head = data;
		tail = data;
	}
	else if (pos == 0) { // if only fist object
		head = data;
		data->setNext(targetNode);
		targetNode->setPrev(data);
	}
	else if (pos == sizeOfList) { // if only last object
		targetNode = tail;
		tail = data;
		data->setPrev(targetNode);
		targetNode->setNext(data);
	}
	else {
		for (int i = 0; i < pos; i++) { // if somewhere in the middle
			targetNode = targetNode->getNext();
		}
		data->setNext(targetNode);
		data->setPrev(targetNode->getPrev());
		targetNode->getPrev()->setNext(data);
		targetNode->setPrev(data);
	}
	sizeOfList += 1;
	return true;
}

bool DoubleLinkedList::remove(int pos) {
	Node *targetNode = head;
	Node *tempNode;
	if (pos > sizeOfList || pos < 0) {
		return false;
	}
	if (pos == 0) {
		tempNode = head;
		head = targetNode->getNext();
		targetNode->getNext()->setPrev(nullptr);
		delete tempNode;
	}
	if (pos == sizeOfList) {
		tempNode = tail;
		tail = targetNode->getPrev();
		targetNode->getPrev()->setNext(nullptr);
		delete tempNode;
	}
	else {
		for (int i = 0; i < pos; i++) {
			targetNode = targetNode->getNext();
		}
		tempNode = targetNode;
		targetNode->getPrev()->setNext(targetNode->getNext());
		targetNode->getNext()->setPrev(targetNode->getPrev());
		delete tempNode;
	}
	sizeOfList -= 1;
	return true;
}

bool DoubleLinkedList::replace(Node* oldNode, Node* newNode) {
	Node *targetNode = head;
	Node *tempNode;

	while (targetNode != nullptr) {
		if (targetNode == oldNode) {
			if (oldNode == head) {
				tempNode = oldNode;
				head = newNode;
			}
			else {
				tempNode = oldNode;
				newNode->setPrev(tempNode->getPrev());
				tempNode->getPrev()->setNext(newNode);

			}
			if (oldNode == tail) {
				tempNode = oldNode;
				tail = newNode;
			}
			else{
				tempNode = oldNode;
				tempNode->getNext()->setPrev(newNode);
				newNode->setNext(tempNode->getNext());
			}
			delete tempNode;
			return true;
		}
		targetNode = targetNode->getNext(); // target next node
	}
	
}

int DoubleLinkedList::search(Node* data) {
	Node *targetNode = head;
	for (int i = 0; i < sizeOfList; i++){

		if (targetNode == data) {
			return i;
		}
		targetNode = targetNode->getNext();

	}
	return -1;
}

Node* DoubleLinkedList::nodeAt(int pos) {
	Node *targetNode = head;
	if (pos < 0 || pos > sizeOfList) {
		return nullptr;
	}
	for (int i = 0; i < pos; i++) {
		targetNode = targetNode->getNext();
	}
	return targetNode;
}

void DoubleLinkedList::displayForward() {
	Node *targetNode = head;
	for (int i = 0; i < sizeOfList; i++) {
		std::cout << targetNode->getData() << ", ";
		targetNode = targetNode->getNext();
	}
	std::cout << std::endl;

}

void DoubleLinkedList::displayBackward() {
	Node *targetNode = tail;
	for (int i = sizeOfList; i > 0; i--) {
		std::cout << targetNode->getData() << ", ";
		targetNode = targetNode->getPrev();
	}
	std::cout << std::endl;
}

int DoubleLinkedList::size() {
	return sizeOfList;
}
