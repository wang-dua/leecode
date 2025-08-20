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

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> result;
		queue<TreeNode*> q{};
		if (root == nullptr) return result;
		q.push(root);

		while (!q.empty())
		{
			int level_size = q.size();
			double sum{};

			for (int i = 0; i < level_size; i++)
			{
				TreeNode* node = q.front();
				q.pop();
				//process
				sum += node->val;

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			result.push_back(sum / level_size);
		}

		return result;

	}
};