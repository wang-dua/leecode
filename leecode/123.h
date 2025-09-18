#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        /*
         * ǰ���ǳ���/δ����
         * ����������������ֱ��������, ��״̬��Ϊ������/��/��/��/�� ����
         * 1. dp[i][j]��ʾi�� ĳ�ֲ����µ��������
         * 2. �ֱ��Ƶ�dp[i][j] j= 0 1 2 3 4
         * 3. ��ʼ��, ��һ��ȫΪ0, ��һ������Ϊ-price, ����Ϊ0(���Ϊ������������)
         * 4. ����
         */

		/*
		 * �����һ��������֮ǰ�ĵ�����������Ϊʲô�� -price, ��ǰ��������в�����һ�м��ϻ�������
		 */
        int m = prices.size();
        //0�޲���/1��һ������/2����/3�ڶ�������/4����
        vector<vector<int>> dp(m, vector<int>(5));

        //��ʼ��
        for (int i = 0; i < m; i++) dp[i][0] = 0;
        dp[0][1] = dp[0][3] = -prices[0];

        for (int i = 1; i < m; i++)
        {
            dp[i][1] = max(dp[i-1][1], 0 - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }

        return dp[m - 1][4];
    }
};
