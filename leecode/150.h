#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
   
public:
    int evalRPN(vector<string>& tokens) {

        //逆波兰表达式即为后缀表达式
        //即后缀表达式变为中缀表达式求值
        //遇到数字入栈, 遇到符号, 弹出栈顶元素作为第二个操作数, 再次弹出栈顶元素作为第一个操作数
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
	            //数字出栈计算, 结果入栈
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
	            //数字入栈
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();

    }
};