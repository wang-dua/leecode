#pragma once

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr)
	{
	}

	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{
	}

	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
	{
	}
};

class Solution
{
public:
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		//确定参数, 返回值
		//确定终止条件
		if (root == nullptr) return root; //1. 没找到key
		//单层递归逻辑
		if (key == root->val)
		{
			if (!root->left && !root->right)
			{
				delete root;
				return nullptr;
			}
			else if (root->left && !root->right)
			{
				TreeNode* node = root->left;
				delete root;
				return node;
			}
			else if (!root->left && root->right)
			{
				TreeNode* node = root->right;
				delete root;
				return node;
			}
			else
			{
				TreeNode* leftestnode = root->right;
				TreeNode* node = root->right;
				while (leftestnode->left != nullptr) //找到右子树的最左节点
				{
					leftestnode = leftestnode->left;
				}
				leftestnode->left = root->left; //右子树的最左节点的左孩子重构
				root->left = nullptr;
				delete root;
				return node;
			}
		}

		if (key < root->val) root->left = deleteNode(root->left, key);
		if (key > root->val) root->right = deleteNode(root->right, key);
		return root;
	}
};
