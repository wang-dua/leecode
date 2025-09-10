#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        /*
         * ��������Ϊ sum/2
         * ��ƷΪnums�е�����, ֵΪ����Ҳ�Ǽ�ֵ
         * ��: �ڱ�������Ϊ sum/2 ʱ, ����ֵΪ sum/2 �Ļ�, �Ǿ��ǿ��Էָ�� 
         */
        int sum{};
        for (int& v : nums) sum += v;
        if (sum % 2 != 0) return false;

    	/*
    	 * 1.dp[j]������Ϊjʱ, ȡ0-i�����ַ��뱳�������ֵ
    	 * 2. dp[j] = max(dp[j], dp[j-weight[i]] + value[i])
    	 * 3. 0��ʼ��
    	 * 4. �������j
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
