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

		//1. dp[i][j], i����Ʒ��� j�Ǳ�������: �ڱ�������Ϊj��, ��(0-i)ѡ�������Ʒװ�뱳��������ֵ
		//����dp[m-1][n]������Ϊnʱ, ѡ�����Է��뱳����Ʒ, ��ʱ��ֵ���

		/*
		 * 2. �Ƶ�: һ����ƷҪôѡ, Ҫô��ѡ, ��������Ϊjʱ, ��Ʒ���Ϊiʱ
		 * ��ѡi, ��ֵΪ dp[i-1][j]
		 * ѡi, ��ֵΪ value[i] + dp[i-1][j-weight[i], dp[i-1][j-weight[i]]��ȥ����i��װ������ֵ
		 * ȡ���ֵ
		 */

		 //3. ��ʼ��:j=0ʱ, ��ֵΪ0, i��i-1�Ƶ�, ��һ���ȳ�ʼ��, ����һ�к͵�һ�г�ʼ��

		 //4. ��������: ����

		vector<vector<int>> dp(m, vector<int>(n + 1)); //�����˿ռ�Ϊ0, ����n+1
		for (int j = 0; j <= n; j++)
		{
			if (weight[0] <= j) dp[0][j] = value[0];
			else dp[0][j] = 0;
		}
		for (int i = 0; i < m; i++) dp[i][0] = 0; //��ʼ��

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
