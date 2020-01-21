#include "DoubleLinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

void main() {
	
	Node* head = nullptr;
	Node* tail = nullptr;
	DoubleLinkedList list(head, tail);

	Node* nodeOne = new Node(1);
	Node* nodeTwo = new Node(2);
	Node* nodeThree = new Node(3);
	Node* nodeFour = new Node(4);
	Node* nodeFive = new Node(5);
	Node* nodeTwenty = new Node(20);

	list.add(nodeOne, 0);
	list.add(nodeTwo, 1);
	list.add(nodeThree, 2);
	list.add(nodeFour, 3);
	list.add(nodeFive, 4);

	list.displayBackward();
	list.remove(2);
	list.replace(nodeFive, nodeTwenty);
	list.displayForward();
	cout << list.search(nodeFour) << endl;
	cout << list.nodeAt(2) << endl;
	cout << list.size() << endl;;
}