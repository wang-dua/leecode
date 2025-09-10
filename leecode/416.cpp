#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        /*
         * 背包容量为 sum/2
         * 物品为nums中的数字, 值为重量也是价值
         * 即: 在背包容量为 sum/2 时, 最大价值为 sum/2 的话, 那就是可以分割的 
         */
        int sum{};
        for (int& v : nums) sum += v;
        if (sum % 2 != 0) return false;

    	/*
    	 * 1.dp[j]是容量为j时, 取0-i号数字放入背包的最大值
    	 * 2. dp[j] = max(dp[j], dp[j-weight[i]] + value[i])
    	 * 3. 0初始化
    	 * 4. 倒序遍历j
    	 */
        int m = nums.size();
        int n = sum / 2;
        vector<int> weight = nums;
        vector<int> value = nums;

        vector<int> dp(n+1, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = n; j >= 0; j--)
            {
                if (j >= weight[i]) dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
            }
        }
        if (dp[n] == n) return true;
        return false;
    }
};
