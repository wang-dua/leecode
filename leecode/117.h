#pragma once
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> q{};
        if (root == nullptr) return root;

        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++)
            {
                Node* node = q.front();
                q.pop();
                if (i != (levelSize - 1))
                {
                    node->next = q.front();
                }
                else
                {
                    node->next = nullptr;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

        }
        return root;
    }
};