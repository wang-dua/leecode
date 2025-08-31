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

    //�����path����ֵ����, ���������, ��ֵ���������ٶ�
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
        } //��Ҷ�ӽڵ�, һ��·���������

        prepath(node->left, path, result); //path��ֵ����, �ݹ��ڲ�Ӱ����һ��
        prepath(node->right, path, result);
    }

    //���ݷ�, path���ô���, �ݹ鷵�غ�, path��Ҫ���ݵ��ݹ�ǰ״̬
    void backtrack(TreeNode* node, std::vector<int>& path, std::vector<std::string>& result)
    {
        if (node == nullptr) return;
        path.push_back(node->val);

		if (!node->left && !node->right)
		{
            std::string str{};
            int i = 0;
			//��pathת��Ϊ vector<string> {1, 3, 5, 6}
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
        path.pop_back(); //��ǰ�ڵ����ĵݹ�, ���غ�pop���ݹ�����ӵ�·��
        
    }

    void backtracking(TreeNode* node, std::vector<int>& path, vector<string>& result)
    {
        if (node == nullptr) return;

        //����ǰ�����, ����Ҷ�Ӿͽ�����Ҷ�ӵ�·������, Ȼ����ݵ��丸�ڵ�
        path.push_back(node->val); //��ӵ�ǰ����
        if (!node->left && !node->right)
        {
            string str{};
            int i = 0;
            for (; i < str.size()-1; i++)
            {
                str += to_string(path[i]);
                str += "->";
            }
            str += to_string(path[i]); //���浽Ҷ�ӵ�·��
            result.push_back(str);
            path.pop_back();   //����Ҷ��Ҫ����
        }
        else
        {
            backtracking(node->left, path, result);
            backtracking(node->right, path, result);
            path.pop_back(); //��һ���������������ݹ����, ҲҪ����, pop����ǰ�ĸ��ڵ�
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