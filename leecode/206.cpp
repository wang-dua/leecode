#include <vector>
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* curr = head;
		ListNode* pre = nullptr;
		ListNode* tmp;

		while (curr)
		{
			tmp = curr->next;
			curr->next = pre;
			pre = curr;
			curr = tmp;
		} 
		return pre;
	}
};

class Solution1 {
public:
	ListNode* Reverse(ListNode* pre, ListNode* curr)
	{
		if (!curr)
			return pre;
		ListNode* tmp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = tmp;
		Reverse(pre, curr);
	}
	ListNode* reverseList(ListNode* head)
	{
		return Reverse(nullptr, head);
	}
};

class Solution2 {
private:
	std::vector<ListNode*> Nodes_;
public:
	ListNode* reverseList(ListNode* head) {
		if (!head)
			return head;
		ListNode* curr = head;
		while (curr)
		{
			Nodes_.push_back(curr);
		}

		auto rhead = Nodes_.back();
		curr = rhead;
		for (int i = 0; i < Nodes_.size(); i++)
		{
			curr->next = Nodes_[i];
		}
		return rhead;
	}
};