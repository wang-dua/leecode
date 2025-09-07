#pragma once
#include <vector>

class Solution {

    //可以转换为深度搜索的问题, 时间复杂度O(2^(m+n))
    int depSearch(int i, int j, int m, int n)
    {
        if (i > m || j > n) return 0;
        if (i == m && j == n) return 1;
        return depSearch(i + 1, j, m, n) + depSearch(i, j+1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        //dp[i][j]表示 走到i,j格子的方法数量
        //推导: dp[i][j] = dp[i-1][j] + dp[i][j-1]
		//初始化dp: 只能向下向右走, 到达最左一列和最上一行的每个格子的方法 都是1
        //遍历方式: 从左到右一行一行遍历

        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        //初始化
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = 1;
        }

        //
        for (int i = 1; i < m; i++)
        {
	        for (int j = 1; j < n; j++)
	        {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	        }
        }
        return dp[m-1][n-1];
    }
};