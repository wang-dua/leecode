#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
	vector<std::vector<int>> generateMatrix(int n)
	{
		int loop = n / 2;
		int offset = 1;
		int xidx = 0, yidx = 0;
		int count = 0;
		vector<vector<int>> res(n, vector<int>(n));
		
		while (loop)
		{
			int i = xidx;
			int j = yidx;
			for (; j < n-offset; j++)
			{
				res[i][j] = count++;
			}
			for (; i < n-offset; i++)
			{
				res[i][j] = count++;
			}
			for (; j > yidx; j--)
			{
				res[i][j] = count++;
			}
			for (; i > xidx; i--)
			{
				res[i][j] = count++;
			}
			offset++;
			xidx++;
			yidx++;
			loop--;
		}
		if (n % 2 != 0) res[n / 2][n / 2] = count;

	}
};
