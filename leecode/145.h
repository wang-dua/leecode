#pragma once
#include <ios>
#include <vector>
#include <stack>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //�п��˳�
        if (root == nullptr) return vector<int>{};
        vector<int> result{};
        vector<int> left_result{};
        vector<int> right_result{};
        //�����������������, ��ӵ�result
        left_result = postorderTraversal(root->left);
        result.insert(result.end(), left_result.begin(), left_result.end());
        //�����������������, ��ӵ� result
        right_result = postorderTraversal(root->right);
        result.insert(result.end(), right_result.begin(), right_result.end());
        //��ӵ�ǰ�ڵ�
        result.push_back(root->val);
        return result;
    }
};


/*������������*/
void postorder(TreeNode* root, vector<int>& result)
{
    // ��ֹ����
    if (root == nullptr) return;
    //left
	postorder(root->left, result);
    //right
	postorder(root->right, result);
    // ��ӽڵ�
    result.push_back(root->val);
}

class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result{};
        postorder(root, result);
        return result;
    }
};

class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st{};
        vector<int> result{};
        if (root == nullptr) return result;

        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            result.push_back(node->val);
            st.pop();

            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);

        }

        reverse(result.begin(), result.end());
        return result;
    }
};