#pragma once
#include <vector>
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
    //二叉搜索树 中序遍历是无重复元素的递增数组
    void traverse(TreeNode* node, std::vector<int>& vec)
    {
        if (node == nullptr) return;
        traverse(node->left, vec);
        vec.push_back(node->val);
        traverse(node->right, vec);
    }


    //前序遍历, 左子树所有值小于node, 右子树所有值大于node
    bool min_max_bound(TreeNode* node, const long long& minval, const long long& maxval)
    {
	    if (node == nullptr) return true;
        //当node不在范围, return false
        if (node->val <= minval || node->val >= maxval) return false;

        //left
        bool bl = min_max_bound(node->left, minval, node->val);
        bool br = min_max_bound(node->right, node->val, maxval);
        return bl && br;
    }

    bool isValidBST(TreeNode* root) {
        return min_max_bound(root, LLONG_MIN, LLONG_MAX);
    }
};