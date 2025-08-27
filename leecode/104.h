#pragma once
#include <queue>
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
    int maxDepth(TreeNode* root) {
        int depth{};
        std::queue<TreeNode*> q{};
        if (root != nullptr) q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};


class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);
        int depth = std::max(ldepth, rdepth) + 1;
    }
};