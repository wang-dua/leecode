#pragma once
#include <vector>
#include <queue>
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


class Solution
{
public:
	/*
	 * ÿ��Ľڵ�ֿ�, ÿ���пյ�ѭ����ʼʱ, �������size���ǵ�ǰ�����нڵ�
	 * ����ʹ��һ��forѭ���ָ�ÿ��
	 */
	std::vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> result{};
		queue<TreeNode*> q{};
		if (root == nullptr) return result;
		q.push(root);

		while (!q.empty())
		{
			int level_size = q.size();
			vector<int> level_result;

			for (int i = 0; i < level_size; i++)
			{
				TreeNode* node = q.front();
				q.pop();
				//����node
				level_result.push_back(node->val);

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			result.push_back(level_result);
		}

		return result;
	}
};
