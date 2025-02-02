#include <iostream>

using namespace std;



class LinkedList {
public:
	class Node {
	public:
		int data;
		Node* next;

		Node(int data, Node *next = nullptr) : data(data), next(next) {}
	};

	LinkedList() {}

	int front() {
		return head ? head->data : -100;
	}

	int back() {
		return tail ? tail->data : -100;
	}

	int size() {
		return _size;
	}

	bool empty() {
		return _size == 0;
	}

	void push_front(int data) {
		_size++;
		auto newNode = new Node(data);

		if (head) {	
			newNode->next = head;
			head = newNode;
		}
		else {
			head = newNode;
			tail = newNode;
		}	
	}

	void push_back(int data) {
		_size++;

		if (tail) {
			auto newNode = new Node(data);
			tail->next = newNode;
			tail = newNode;
		}
		else {
			push_front(data);
		}	
	}

	void insert(int data, int pos) {
		if (this->empty() || pos >= _size) return;

		if (pos == 0) {
			push_front(data);
			return;
		}
		else if (pos == _size - 1) {
			push_back(data);
			return;
		}

		_size++;
		Node* prev = nullptr;
		Node* curr = head;

		while (pos != 0 && curr) {
			prev = curr;
			curr = curr->next;
			pos--;
		}
		
		auto newNode = new Node(data);
		prev->next = newNode;
		newNode->next = curr;
	}

	void pop_front() {
		if (this->empty()) return;

		_size--;
		auto oldHead = head;
		if (this->size() == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete oldHead;
	}

	void pop_back() {
		if (this->empty()) return;

		_size--;
		auto oldTail = tail;
		if (this->size() == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			auto curr = head;
			while (curr->next != oldTail) {
				curr = curr->next;
			}
			
			tail = curr;
			tail->next = nullptr;
		}
		delete oldTail;
	}

	
	// reg case
	
	void remove(int pos) {
		if (this->empty() || pos >= _size) return;

		if (pos == 0) {
			pop_front();
			return;
		}
		else if (pos == _size - 1) {
			pop_back();
			return;
		}

		_size--;
		Node* prev = nullptr;
		Node* curr = head;

		while (pos != 0 && curr) {
			prev = curr;
			curr = curr->next;
			pos--;
		}

		prev->next = curr->next;
		delete curr;
	}

	void print() {
		if (this->empty()) return;
		
		cout << "Head: " << head->data
			 << ", Tail: " << tail->data
			 << ", Size: " << _size << endl;
		
		auto curr = head;
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int _size = 0;
};

#include <vector>
#include <list>
#include <algorithm>
#include <string>

//bool cmp(const int& a, const int& b) {
//	return a > b;
//}

int main()
{
	string s1 = "Hello";
	string s2 = ", World!";
	string res = s1 + s2;

	cout << res;
}