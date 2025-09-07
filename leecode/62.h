#pragma once
#include <vector>

class Solution {

    //����ת��Ϊ�������������, ʱ�临�Ӷ�O(2^(m+n))
    int depSearch(int i, int j, int m, int n)
    {
        if (i > m || j > n) return 0;
        if (i == m && j == n) return 1;
        return depSearch(i + 1, j, m, n) + depSearch(i, j+1, m, n);
    }

public:
    int uniquePaths(int m, int n) {
        //dp[i][j]��ʾ �ߵ�i,j���ӵķ�������
        //�Ƶ�: dp[i][j] = dp[i-1][j] + dp[i][j-1]
		//��ʼ��dp: ֻ������������, ��������һ�к�����һ�е�ÿ�����ӵķ��� ����1
        //������ʽ: ������һ��һ�б���

        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        //��ʼ��
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