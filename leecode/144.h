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
    //��ֹ����
    if (root == nullptr)
    {
        return;
    }
    //��ӵ�ǰ�Ľڵ�
    result.push_back(root->val);
    //��ǰ�ڵ��������
    preorder(root->left, result);
    //������
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

//������������
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
		 * ÿ��ѭ������ջ��Ԫ��, ����ջ��Ԫ�ص��Һ�������������ջ
		 */
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val); //�нڵ�

            /*
             * �սڵ㲻��ջ, ����ջ�ҽڵ�, ����ջ��ڵ�
             */
            if (node->right) st.push(node->right); 
            if (node->left) st.push(node->left);

        }
        return result;
    }
};
