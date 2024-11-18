#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

class Node {
public:
	int data;
	Node* next;

	Node(int data, Node* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};

class List {
public:
	Node* head;
	Node* tail;

	List() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	// Interface

	void push_front(int val) {
		Node* newNode = new Node(val, head);
		head = newNode;

		if (tail == nullptr) {
			tail = newNode;
		}
	}

	void push_back(int val) {
		Node* newNode = new Node(val);

		if (tail) {
			tail->next = newNode;
			tail = newNode;
		}
		else {
			head = newNode;
			tail = newNode;
		}
	}

	void pop_front() {
		if (this->empty()) return;

		Node* oldHead = head;
		head = head->next;
		delete oldHead;

		if (this->empty()) tail = nullptr;
	}

	void pop_back() {
		if (this->empty()) return;

		Node* newTail = nullptr;
		Node* toTail = head;

		while (toTail != tail) {
			newTail = toTail;
			toTail = toTail->next;
		}

		delete toTail;
		tail = newTail;

		if (tail) {
			tail->next = nullptr;
		}
		else {
			head = nullptr;
		}
	}

	void insert(int val, int index) {
		if (index == 0) {
			push_front(val);
			return;
		}

		if (head == nullptr) {
			return;
		}

		Node* newNode = new Node(val);
		Node* beforeTarget = nullptr;
		Node* toTarget = head;
		int currIndex = 0;

		while (toTarget && currIndex != index) {
			beforeTarget = toTarget;
			toTarget = toTarget->next;
			currIndex++;
		}

		if (currIndex == index) {
			beforeTarget->next = newNode;
			newNode->next = toTarget;
		}
		else {
			return;
		}
	}

	void remove(int index) {
		if (index < 0 || index >= size()) return;

		if (index == 0) {
			pop_front();
			return;
		}

		Node* beforeTarget = nullptr;
		Node* toTarget = head;

		for (int i = 0; i < index; i++)
		{
			beforeTarget = toTarget;
			toTarget = toTarget->next;
		}

		beforeTarget->next = toTarget->next;
		delete toTarget;
	}

	void removeValues(int val) {
		if (empty()) return;
		Node* beforeTarget = nullptr;
		Node* toTarget = head;

		while (toTarget) {
			// Remove element if needed
			if (toTarget->data == val) {
				if (beforeTarget) {
					beforeTarget->next = toTarget->next;
					Node* toDelete = toTarget;
					toTarget = toTarget->next;
					delete toDelete;
				}
				else {
					toTarget = toTarget->next;
					pop_front();
				}
			}
			else {
				// Move ptrs
				beforeTarget = toTarget;
				toTarget = toTarget->next;
			}
		}
	}

	void reverse() {
		if (empty()) return;

		Node* bt = nullptr; // Before target
		Node* tt = head; // To target
		Node* at = head->next; // After target

		while (true) {
			tt->next = bt;

			if (at) {
				bt = tt;
				tt = at;
				at = at->next;
			}
			else {
				break;
			}
		}


		std::swap(head, tail);
	}

	int at(int index) {
		Node* target = head;
		int currIndex = 0;

		while (target != tail && currIndex != index) {
			target = target->next;
			currIndex++;
		}

		if (currIndex == index) {
			return target->data;
		}
		else {
			return -1111;
		}
	}

	int size() {
		Node* curr = head;
		int size = 0;

		while (curr) {
			size++;
			curr = curr->next;
		}

		return size;
	}

	bool empty() {
		return head == nullptr;
	}

	// Utility

	void print() {
		Node* curr = head;

		while (curr) {
			std::cout << curr->data << ", ";
			curr = curr->next;
		}

		std::cout << std::endl;
	}

	void printAt(int index) {
		std::cout << "Value at " << index << ": " << at(index) << std::endl;
	}
};

// TODO:
// -> Better insert [DONE]
// -> Implement remove [DONE]
// -> Reverse [DONE]
// -> Make doubly-linked
// -> Print middle element
// -> Print element in proportion (1/2 would be the middle)
// -> Detect Cycle
// -> Merge sort
// -> Remove duplicates
// -> Remove all with value [DONE]
