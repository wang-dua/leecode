#pragma once
#include <algorithm>
#include <cstdlib>

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
    int depth(TreeNode* node)
    {
        if (node == nullptr) return 0;
        int ld = depth(node->left);
        if (ld == -1) return -1;
        int rd = depth(node->right);
        if (rd == -1) return -1;

        int dif = abs(ld - rd);
        if (dif > 1) return -1;
        if (dif <= 1) return std::max(ld, rd) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int b = depth(root);
        if (b == -1) return false;
        return true;
    }
};