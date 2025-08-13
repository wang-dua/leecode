#pragma once
#include <stack>
#include <string>
#include <iostream>
class Solution {
public:
    bool isValid(std::string s) {
        //���ȼ���ַ��������Ƿ�Ϊż��
        //�����ַ���, ����������, ����Ӧ����������ջ, ����������, ����ջ��Ԫ�ؼ���Ƿ���ͬ
        //�����ֲ�ƥ�����
        //1 �����űȽ϶�, �ַ���������������ջ�ڻ���Ԫ��
        //2 �����űȽ϶�, �ַ�������δ��������ջ����Ԫ��
        //3 ����һ����, �������Ų�ƥ��
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
            else if (st.empty()) //2 �ڱ���������, stack����, �����Ŷ�
            {
                std::cout << "right\n";
                return false;
            }
            else if (st.top() != ch) //3 ������, ���������Ų�ƥ��
            {
                std::cout << "match\n";
                return false;
            }
            else
            {
                st.pop(); //ƥ��, ����ջ��Ԫ��
            }
        }

        //1 �����Ŷ�
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
