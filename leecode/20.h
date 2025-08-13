#pragma once
#include <stack>
#include <string>
#include <iostream>
class Solution {
public:
    bool isValid(std::string s) {
        //首先检查字符串长度是否为偶数
        //遍历字符串, 遇到左括号, 将相应的右括号入栈, 遇到右括号, 弹出栈顶元素检查是否相同
        //有三种不匹配情况
        //1 左括号比较多, 字符串遍历结束但是栈内还有元素
        //2 右括号比较多, 字符串遍历未结束但是栈内无元素
        //3 左右一样多, 但是括号不匹配
        if (s.size() % 2 != 0)
            return false;
        std::stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(')
                st.push(')');
            else if (ch == '[')
            {
                st.push(']');
            }
            else if (ch == '{')
                st.push('}');
            else if (st.empty()) //2 在遍历过程中, stack空了, 右括号多
            {
                std::cout << "right\n";
                return false;
            }
            else if (st.top() != ch) //3 遍历中, 出现了括号不匹配
            {
                std::cout << "match\n";
                return false;
            }
            else
            {
                st.pop(); //匹配, 弹出栈顶元素
            }
        }

        //1 左括号多
        if (!st.empty())
        {
            std::cout << "left\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};
