struct ListNode
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr)
	{
	}

	ListNode(int x) : val(x), next(nullptr)
	{
	}

	ListNode(int x, ListNode* next) : val(x), next(next)
	{
	}
};


class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		while (head && head->val == val)
		{
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
		}
		ListNode* curr = head;
		ListNode* rhead = head;
		while (curr->next)
		{
			ListNode* tmp = curr->next;
			if (tmp->val == val)
			{
				curr->next = tmp->next;
				delete tmp;
			}
			else
			{
				curr = curr->next;
			}
		}
		return rhead;
		//ListNode* dummyHead = new ListNode(0, head);
		//ListNode* curr = dummyHead;
		//if (head == nullptr)
		//	return head;
		////未删除节点curr继续遍历, 如果删除了节点curr无需移动
		////小心边界的nullptr
		//while (!(curr->next))
		//{
		//	ListNode* temp = curr->next;
		//	if (temp->val == val)
		//	{
		//		curr->next = temp->next;
		//		delete temp;
		//	}
		//	else curr = curr->next; 
		//}
		//head = dummyHead->next;
		//delete dummyHead;
		//return head;
	}
};
