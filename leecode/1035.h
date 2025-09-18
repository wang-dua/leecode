#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (nums1[i] == nums2[0]) dp[i][0] = 1;
            else if (i > 0)
            {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (nums2[j] == nums1[0]) dp[0][j] = 1;
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
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m - 1][n - 1];

    }
};
