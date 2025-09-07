#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m)); //n, m Íø¸ñ

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
			}
		}

		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
			if (dp[i][0] > 0)
			{
				dp[i][0] = 0;
			}
	
		}
		for (int j = 1; i < m; i++)
		{
			dp[0][j] = dp[0][j - 1] + grid[0][j];
			if (dp[0][j] > 0)
			{
				dp[0][j] = 0;
			}
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				int from_top = dp[i - 1][j] + grid[i][j];
				int from_left = dp[i][j - 1] + grid[i][j];
				dp[i][j] = max(from_top, from_left);
				if (dp[i][j] > 0) dp[i][j] = 0;
			}
		}
		cout << 1 - dp[n - 1][m - 1] << endl;

		return 0;



	}
}