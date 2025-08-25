#pragma once
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node();

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result{};
        queue<Node*> q;

        if (root != nullptr) q.push(root);
        while (!q.empty())
        {
            int size = q.size(); //首先确定当前层节点数
            vector<int> vec{};
            for (int i = 0; i < size; i++)
            {
                Node* node = q.front();
                vec.push_back(node->val);
                q.pop();

                //将节点的children全部入队
                for (int j = 0; j < node->children.size(); j++)
                {
                    q.push(node->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};