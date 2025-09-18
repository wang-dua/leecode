#pragma once
class MyLinkedList {
private:
	class Node
	{
	public:
        Node* next;
        Node* prev;
        int val;
        Node() = default;
        Node(int v): val(v), next(nullptr), prev(nullptr){}
	};
private:
    Node* head;
    Node* rear;
public:
    MyLinkedList() {
        head = new Node();
        rear = new Node();
        head->next = rear;
        rear->prev = head;
    }

    int get(int index) { //index是下标
        Node* cur = head;
        if (index < 0) return -1;
        for (int i = 0; i <= index; i++)
        {
            cur = cur->next;
            if (cur == rear) return -1;
          
        }
        return cur->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next->prev = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        newNode->next = rear;
        newNode->prev = rear->prev;
        rear->prev->next = newNode;
        rear->prev = newNode;
    }

    void addAtIndex(int index, int val) {
        //在索引index插入, 找到索引index, 在其前面插入
        Node* cur = head;
        for (int i = 0; i <= index; i++)
        {
            cur = cur->next;
            if (cur == rear && i < index) return;
        }
        Node* newNode = new Node(val);
        newNode->next = cur;
        newNode->prev = cur->prev;
        cur->prev->next = newNode;
        cur->prev = newNode;

    }

    void deleteAtIndex(int index) {
        Node* cur = head;
        for (int i = 0; i <= index; i++)
        {
            cur = cur->next;
            if (cur == rear) return;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */