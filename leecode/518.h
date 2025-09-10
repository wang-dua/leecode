#pragma once
#include <vector>
using namespace std;
class Solution {
    vector<int> path{};
    vector<vector<int>> result{};
public:
/*
 * �������������, �����û��ݷ����, ���ǻ��ݷ�Ч�ʵ�, ��target�ܴ�ʱ, ��ջ��� (���ݷ�: �ӷ��ظ�����ȥ��Ԫ��, Ԫ�ؿ����ظ�)
 *
 * ����ʹ����ȫ�������, dp[i][j]��ŵ��� ��ǰ����Ϊjʱ, �ӱ��0-i����ȡ��, ��Ϊj��������� ����
 */
    void backtracking(vector<int>& nums, int target, int sum, int startidx)
    {
	    //ʲôʱ�򷵻�
        //forѭ������
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

        //��ʼ��
        vector<vector<uint64_t>> dp(m, vector<uint64_t>(n+1, 0));
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1; //����ȡ����, �����֮��Ϊ0, ��һ�ַ���----��һ�г�ʼ��
        }
        for (int j = 0; j <= n; j++)
        {
            if (j % coins[0] == 0) dp[0][j] = 1; //ȡģΪ0, �������, ��һ�ַ���---��һ�г�ʼ��
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
                    //��ʹ��i����ϸ��� + ����ʹ��һ��i(��ȥ�ռ�i)����ϸ���
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
		        }
	        }
        }

        return dp[m-1][n];
    }
};
