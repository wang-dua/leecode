#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //dp[i] �� ����į�׵���С����, n��̨�� + 1, Ϊ¥�ݶ���
        //dp[i] = 
        //��ʼ��dp, dp[0] = dp[1] = 0
        //ȷ������˳��, ��ǰ�������cost

        int n = cost.size();
        if (n <= 2)
        {
            return min(cost[0], cost[1]);
        }
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
            
        }
        for (auto& i: dp)
        {
            cout << i << " ";
        }
        cout << "\n";
        return dp.back();
    }
};