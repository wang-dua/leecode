#pragma once
#include <fenv.h>
#include <vector>
#include <string>
using namespace  std;
 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {

    //这里的path采用值传递, 较容易理解, 但值拷贝降低速度
    void prepath(TreeNode* node, std::string path, std::vector<std::string>& result)
    {
        if (node == nullptr) return;
        if (!path.empty())
        {
            path += "->";
        }
        path += to_string(node->val);
        if (!node->left && !node->right)
        {
            result.push_back(path);
        } //到叶子节点, 一条路径生成完毕

        prepath(node->left, path, result); //path按值传递, 递归内不影响上一层
        prepath(node->right, path, result);
    }

    //回溯法, path引用传参, 递归返回后, path需要回溯到递归前状态
    void backtrack(TreeNode* node, std::vector<int>& path, std::vector<std::string>& result)
    {
        if (node == nullptr) return;
        path.push_back(node->val);

		if (!node->left && !node->right)
		{
            std::string str{};
            int i = 0;
			//把path转化为 vector<string> {1, 3, 5, 6}
            for (; i < path.size() - 1; i++) 
            {
                str += to_string(path[i]);
                str += "->";
            }
            str += to_string(path[i]);
            result.push_back(str);
		}
		else
		{
            backtrack(node->left, path, result);
            backtrack(node->right, path, result);
		}
        path.pop_back(); //当前节点进入的递归, 返回后pop掉递归中添加的路径
        
    }

    void backtracking(TreeNode* node, std::vector<int>& path, vector<string>& result)
    {
        if (node == nullptr) return;

        //采用前序遍历, 遇到叶子就将根到叶子的路径保存, 然后回溯到其父节点
        path.push_back(node->val); //添加当前树根
        if (!node->left && !node->right)
        {
            string str{};
            int i = 0;
            for (; i < str.size()-1; i++)
            {
                str += to_string(path[i]);
                str += "->";
            }
            str += to_string(path[i]); //保存到叶子的路径
            result.push_back(str);
            path.pop_back();   //遇到叶子要回溯
        }
        else
        {
            backtracking(node->left, path, result);
            backtracking(node->right, path, result);
            path.pop_back(); //当一个树的左右子树递归完成, 也要回溯, pop掉当前的根节点
        }

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> result{};
        std::string path{};
        prepath(root, path, result);
        return result;
    }
};