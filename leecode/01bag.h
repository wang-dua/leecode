#pragma once
#include <vector>
#include <iostream>
using namespace std;

class BAG_01
{
public:
	int bag_01()
	{
		int m, n;
		while (cin >> m >> n)
		{
			if (m > 0 && n > 0) break;
		}

		vector<int> weight(m);
		vector<int> value(m);
		int space, val;
		for (int i = 0; i < m && cin >> space; i++) weight[i] = space;
		for (int i = 0; i < m && cin >> val; i++) value[i] = val;

		//1. dp[i][j], i是物品编号 j是背包容量: 在背包容量为j下, 在(0-i)选出编号物品装入背包的最大价值
		//所以dp[m-1][n]是容量为n时, 选出可以放入背包物品, 此时价值最大

		/*
		 * 2. 推导: 一个物品要么选, 要么不选, 背包容量为j时, 物品编号为i时
		 * 不选i, 价值为 dp[i-1][j]
		 * 选i, 价值为 value[i] + dp[i-1][j-weight[i], dp[i-1][j-weight[i]]是去除了i能装的最大价值
		 * 取最大值
		 */

		 //3. 初始化:j=0时, 价值为0, i由i-1推导, 第一行先初始化, 即第一行和第一列初始化

		 //4. 遍历过程: 按行

		vector<vector<int>> dp(m, vector<int>(n + 1)); //包含了空间为0, 所以n+1
		for (int j = 0; j <= n; j++)
		{
			if (weight[0] <= j) dp[0][j] = value[0];
			else dp[0][j] = 0;
		}
		for (int i = 0; i < m; i++) dp[i][0] = 0; //初始化

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j < weight[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);

			}
		}


		return dp[m - 1][n];
	}
};
