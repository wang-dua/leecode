#pragma once
#include <vector>
using namespace std;
class Solution {
    vector<int> path{};
    vector<vector<int>> result{};
public:
/*
 * 本质是求组合数, 可以用回溯法解决, 但是回溯法效率低, 当target很大时, 会栈溢出 (回溯法: 从非重复数组去除元素, 元素可以重复)
 *
 * 可以使用完全背包解决, dp[i][j]存放的是 当前容量为j时, 从编号0-i数字取出, 和为j的组合数的 数量
 */
    void backtracking(vector<int>& nums, int target, int sum, int startidx)
    {
	    //什么时候返回
        //for循环回溯
        if (sum > target) return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = startidx; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            sum += i;
            backtracking(nums, target, sum, i);
            path.pop_back();
            sum -= i;
        }
    }

    int change(int amount, std::vector<int>& coins) {
        int m = coins.size();
        int n = amount;

        //初始化
        vector<vector<uint64_t>> dp(m, vector<uint64_t>(n+1, 0));
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1; //当不取数字, 组合数之和为0, 是一种方法----第一列初始化
        }
        for (int j = 0; j <= n; j++)
        {
            if (j % coins[0] == 0) dp[0][j] = 1; //取模为0, 可以组合, 是一种方法---第一行初始化
        }


        int sum{};

        for (int i = 1; i < m; i++)
        {
	        for (int j = 1; j <= n; j++)
	        {
		        if (coins[i] > j)
		        {
                    dp[i][j] = dp[i - 1][j];
		        }
		        else
		        {
                    //不使用i的组合个数 + 至少使用一个i(减去空间i)的组合个数
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
		        }
	        }
        }

        return dp[m-1][n];
    }
};
