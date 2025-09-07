#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {

        //dp[i] �� �� i��̨�׵ķ���
        if (n < 2) return n;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n+1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];

        }
        return dp[n]; //n��̨�׵ķ�����Ŀ��dp[n]
    }
};