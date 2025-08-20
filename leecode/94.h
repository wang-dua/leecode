#pragma once
#include <vector>
#include <stack>
using namespace std;

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

void inorder(TreeNode* root, vector<int>& result)
{
	if (root == nullptr) return;
	inorder(root->left, result);
	result.push_back(root->val);
	inorder(root->right, result);
}
class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result{};
		inorder(root, result);
		return result;
	}
};


class Solution1
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result{};
		stack<TreeNode*> st{};

		TreeNode* node = root;
		while (node != nullptr || !st.empty())
		{
			if (node != nullptr)
			{
				st.push(node);
				node = node->left;
			} //һֱ��������������, �ýڵ������Ҷ�ӻ���û��������
			else
			{
				node = st.top();
				st.pop();
				result.push_back(node->val); //����

				node = node->right;
			}

		}


		return result;
	}
};