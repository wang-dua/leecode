#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit_01(std::vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        int low = dp[0];
        for (int i = 1; i < n; i++)
        {
            low = min(low, prices[i]);
            dp[i] = max(dp[i-1], prices[i] - low);
        }
        return dp[n - 1];
    }

    int maxProfit(std::vector<int>& prices) {
    	        
		
        int m = prices.size();
        vector<vector<int>> dp(m, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        return dp[m - 1][0];
    }

    
};
