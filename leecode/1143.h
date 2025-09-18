#pragma once
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, std::string text2) {
        //dp[i][j]: 以text1[i], text2[j]为结尾的两个序列的最长公共子序列长度
        //推导: 子序列不要求连续, 在之前求递增子序列长度的时候, d[i] = max(d[i], d[0-j] + 1)
		/*
		 * 现在还得要求相等
		 */
        //初始化: 
        //遍历:
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (text1[i] == text2[0]) dp[i][0] = 1;
            else if (i > 0)
            {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (text2[j] == text1[0]) dp[0][j] = 1;
            else if (j > 0)
            {
                dp[0][j] = dp[0][j - 1];
            }
        }
        //int result{};, 因为求子序列, 数值不会像求公共数组那样中断, 所以不使用result
        for (int i = 1; i < m; i++)
        {
	        for (int j = 1; j < n; j++)
	        {
		        if (text1[i] == text2[j])
		        {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
		        }
		        else
		        {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		        }
	        }
        }
        return dp[m-1][n-1];
    }
};
