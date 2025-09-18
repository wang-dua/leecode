#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        /*
         * 前面是持有/未持有
         * 这次由于限制买卖分别最多两次, 将状态分为不操作/买/卖/买/卖 五列
         * 1. dp[i][j]表示i日 某种操作下的最大收益
         * 2. 分别推导dp[i][j] j= 0 1 2 3 4
         * 3. 初始化, 第一列全为0, 第一行买入为-price, 卖出为0(理解为当天买入卖出)
         * 4. 遍历
         */

		/*
		 * 结合这一题可以理解之前的单词买入卖出为什么是 -price, 把前面的两题中不操作一列加上会更好理解
		 */
        int m = prices.size();
        //0无操作/1第一次买入/2卖出/3第二次买入/4卖出
        vector<vector<int>> dp(m, vector<int>(5));

        //初始化
        for (int i = 0; i < m; i++) dp[i][0] = 0;
        dp[0][1] = dp[0][3] = -prices[0];

        for (int i = 1; i < m; i++)
        {
            dp[i][1] = max(dp[i-1][1], 0 - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }

        return dp[m - 1][4];
    }
};
