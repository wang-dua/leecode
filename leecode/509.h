#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        //确定dp数组以及下标的含义, dp[i]是i的斐波那契数
        //递推公式 fib(n) = fib(n-1) + fib(n-2)
        //初始化dp数组
        //确定数组的遍历顺序
        //举例推导dp数组
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