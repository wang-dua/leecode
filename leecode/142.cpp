struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr)
	{
	}
};
//pos 是环形入口处索引
class Solution
{
public:
	ListNode* detectCycle(ListNode* head)
	{
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				while (slow != head)
				{
					slow = slow->next;
					head = head->next;
				}
				return slow;
			}
		}
		return nullptr;

	}
};
