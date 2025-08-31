#pragma once
#include <algorithm>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {

public:
    TreeNode* searchBST(TreeNode* root, int val) {

        //ȷ�������ͷ���ֵ, root, val,
        //ȷ����ֹ����, ����val����nullptr
        //����ݹ��߼�: ��val����

        if (root == nullptr) return nullptr;

        if (val == root->val)
        {
            return root;
        }

        if (val < root->val)
        {
            return searchBST(root->left, val);
        }

        if (val > root->val)
        {
            return searchBST(root->right, val); 
        }

        return nullptr;
    }

    TreeNode* itBST(TreeNode* root, int val)
    {
	    if (root == nullptr) return nullptr;
	    while (root)
	    {
            if (root->val == val) return root;
            if (val < root->val) root = root->left;
            if (val > root->val) root = root->right;
	    }
    }
};