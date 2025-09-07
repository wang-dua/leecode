#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        //ȷ��dp�����Լ��±�ĺ���, dp[i]��i��쳲�������
        //���ƹ�ʽ fib(n) = fib(n-1) + fib(n-2)
        //��ʼ��dp����
        //ȷ������ı���˳��
        //�����Ƶ�dp����
        if (n < 2) return n;
        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = 1;
        int result{};
        for (int i = 2; i < n+1; i++)
        {
            result = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = result;
        }
        return dp[1];
    }
};