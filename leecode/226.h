#pragma once
#include <queue>
#include <stack>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution_level {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> q;
        if (root != nullptr) q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                TreeNode* temp{};
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right); //先入队, 先处理业务会导致左右颠倒

                temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
        }
        return root;
    }
};

class Solution_pre {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* currNode = root;
        if (currNode == nullptr) return currNode;
        //
        TreeNode* temp{};
        temp = currNode->left;
        currNode->left = currNode->right;
        currNode->right = temp;

        //左
        invertTree(currNode->left);
        //右
        invertTree(currNode->right);

        return root;
    }
};