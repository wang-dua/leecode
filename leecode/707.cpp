#include <iostream>
#include <list>
using namespace  std;
class MyLinkedList
{
private:
	struct Node
	{
		int value;
		Node* next;
		Node* prev;
		Node() : value{}, next(nullptr), prev(nullptr) {}
		explicit Node(int v) : value(v), next(nullptr), prev(nullptr) {}
	};
	typedef Node* LinkListNode;

private:
	LinkListNode dummyHead;
	LinkListNode dummyTail;
	size_t size_;
public:
	MyLinkedList(): dummyHead(), dummyTail(), size_(0)
	{
		dummyHead = new Node();
		dummyTail = new Node();
		dummyHead->next = dummyTail;
		dummyTail->prev = dummyHead;
	}

	int get(int index)
	{
		if (size_ == 0)
			return -1;
		if (index < 0 || index > (size_ - 1))
			return -1;

		LinkListNode curr = dummyHead;
		for (int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
		return curr->next->value;
	}

	void addAtHead(int val) {
		LinkListNode newNode = new Node(val);
		newNode->next = dummyHead->next;
		newNode->prev = dummyHead;
		dummyHead->next = newNode;
		newNode->next->prev = newNode;
		size_++;
	}

	void addAtTail(int val) {
		LinkListNode newNode = new Node(val);
		newNode->prev = dummyTail->prev;
		newNode->next = dummyTail;
		dummyTail->prev = newNode;
		newNode->prev->next = newNode;
		size_++;
	}

	void addAtIndex(int index, int val) { 
		if (index < 0 || index > size_) //index [0, size_]
			return;

		LinkListNode newNode = new Node(val);
		auto curr = dummyHead;
		for (int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
		newNode->next = curr->next;
		newNode->prev = curr;
		curr->next = newNode;
		newNode->next->prev = newNode;
		size_++;
	}

	void deleteAtIndex(int index) {
		
		if (size_ == 0)
			return;
		if (index < 0 || index > (size_ - 1))
			return;
		auto curr = dummyHead;
		for (int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
		LinkListNode tmp = curr->next;
		curr->next = tmp->next;
		curr->next->prev = curr;
		delete tmp;
		size_--;
	}

	void prinStatus()
	{
		LinkListNode curr = dummyHead->next;
		while (curr != dummyTail)
		{
			cout << curr->value << " ";
			curr = curr->next;
		}
	}
};
