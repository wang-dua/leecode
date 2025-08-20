#pragma once
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorder(TreeNode* root, vector<int>& result)
{
    //终止条件
    if (root == nullptr)
    {
        return;
    }
    //添加当前的节点
    result.push_back(root->val);
    //当前节点的左子树
    preorder(root->left, result);
    //右子树
    preorder(root->right, result);
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        /*vector<int> result;
        if (root == nullptr) return vector<int>{};
        result.push_back(root->val);
        auto left = preorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        auto right = preorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
        return result;*/
    }
};

//借助辅助函数
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        preorder(root, pre);
        return pre;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode*> st;
        vector<int> result{};

        if (root == nullptr) return result;

        st.push(root);
		/*
		 * 每次循环弹出栈顶元素, 并将栈顶元素的右孩子左孩子依次入栈
		 */
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val); //中节点

            /*
             * 空节点不入栈, 先入栈右节点, 再入栈左节点
             */
            if (node->right) st.push(node->right); 
            if (node->left) st.push(node->left);

        }
        return result;
    }
};
