#pragma once
#include <vector>
#include <iostream>

class fullBag
{
public:
	int full_bag()
	{
		int m, n;
		std::cin >> m >> n;
		std::vector<int> weight(m);
		std::vector<int> value(m);
		for (int i = 0; i < m; i++) std::cin >> weight[i] >> value[i];

		//≥ı ºªØ
		std::vector<std::vector<int>> dp(m, std::vector<int>(n+1, 0));
		for (int j = 1; j <= n; j++)
		{
			dp[0][j] = j / weight[0] * value[0];
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (weight[i] > j)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
				}
			}
		}
		return dp[m-1][n];

	}

	int full_bag_oneD()
	{
		int m, n;
		std::cin >> m >> n;
		std::vector<int> weight(m);
		std::vector<int> value(m);
		for (int i = 0; i < m; i++) std::cin >> weight[i] >> value[i];

		std::vector<int> dp(n+1, 0); //one Dimension
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (weight[i] <= j) dp[j] = std::max(dp[j], dp[j-weight[i]] + value[i]);
			}
		}
		return dp[n];
	}
};
