#pragma once

   struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummyhead = new ListNode();
        ListNode* cur = dummyhead;

        while (cur->next)
        {
            if (cur->next->val == val)
            {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummyhead->next;
    }
};