#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
   
public:
    int evalRPN(vector<string>& tokens) {

        //�沨�����ʽ��Ϊ��׺���ʽ
        //����׺���ʽ��Ϊ��׺���ʽ��ֵ
        //����������ջ, ��������, ����ջ��Ԫ����Ϊ�ڶ���������, �ٴε���ջ��Ԫ����Ϊ��һ��������
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
	            //���ֳ�ջ����, �����ջ
                int number_1 = st.top();
                st.pop();
                int number_2 = st.top();
                st.pop();
                if (tokens[i] == "+")
                {
                    st.push(number_2 + number_1);
                    continue;
                }
                if (tokens[i] == "-")
                {
                    st.push(number_2 - number_1);
                    continue;
                }
                if (tokens[i] == "*")
                {
                    st.push(number_2 * number_1);
                    continue;
                }
                if (tokens[i] == "/")
                {
                    st.push(number_2 / number_1);
                    continue;
                }

            }
            else
            {
	            //������ջ
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();

    }
};