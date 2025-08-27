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

bool recursive(TreeNode*, TreeNode*);
bool useQueue(TreeNode*, TreeNode*);
bool useStack(TreeNode*, TreeNode*);
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return recursive(root->left, root->right);
    }
};

inline bool recursive(TreeNode* leftside, TreeNode* rightside)
{
    if (leftside == nullptr && rightside != nullptr) return false;
    else if (leftside != nullptr && rightside == nullptr) return false;
    else if (leftside == nullptr && rightside == nullptr) return true;
    else if (leftside != nullptr && rightside != nullptr && leftside->val != rightside->val)
        return false; 
    else //当左侧右侧都非空, 且对称, 才会进入下一层递归
    {
	    //out
        bool outbool = recursive(leftside->left, rightside->right);
        bool inbool = recursive(leftside->right, rightside->left);
        return outbool && inbool; //内外都true才会true
    }
}

inline bool useQueue(TreeNode* leftside, TreeNode* rightside)
{
    std::queue<TreeNode*> q{};
    q.push(leftside);
    q.push(rightside);

    while (!q.empty())
    {
        TreeNode* lnode = q.front();
        q.pop();
        TreeNode* rnode = q.front();
        q.pop();

		
        if (lnode == nullptr && rnode != nullptr) return false;
        else if (lnode != nullptr && rnode == nullptr) return false;
        else if (lnode != nullptr && rnode != nullptr && lnode->val != rnode->val) return false;
        //都空的时候直接跳过本次循环, 判断下一对
        else if (lnode == nullptr && rnode == nullptr) continue;
        //当都非空且对称才能继续下面的入队
        else
        {
            //outside入队
            q.push(lnode->left);
            q.push(rnode->right);

            //inside入队
            q.push(lnode->right);
            q.push(rnode->left);
        }
    }
    return true;
}

inline bool useStack(TreeNode* leftside, TreeNode* rightside)
{
    std::stack<TreeNode*> st{};
    st.push(leftside);
    st.push(rightside);

    while (!st.empty())
    {
        TreeNode* lnode = st.top();
        st.pop();
        TreeNode* rnode = st.top();
        st.pop();


        if (lnode == nullptr && rnode != nullptr) return false;
        else if (lnode != nullptr && rnode == nullptr) return false;
        else if (lnode != nullptr && rnode != nullptr && lnode->val != rnode->val) return false;
        //都空的时候直接跳过本次循环, 判断下一对
        else if (lnode == nullptr && rnode == nullptr) continue;
        //当都非空且对称才能继续下面的入队
        else
        {
            //outside入队
            st.push(lnode->left);
            st.push(rnode->right);

            //inside入队
            st.push(lnode->right);
        	st.push(rnode->left);
        }
    }
    return true;
}