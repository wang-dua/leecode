#pragma once
#include <vector>
using namespace std;
class Solution {
	vector<int> path{};
	vector<vector<int>> result{};

	void backtracking(int k, int n, int startidx)
	{
		if (path.size() == k)
		{
			int sum{};
			for (auto& val : path) { sum += val; }
			if (sum == n)
			{
				result.push_back(path);
			}
			return;
		}

		for (int i = startidx; i <= 9; i++)
		{
			//Âú×ãÌõ¼þif()
			path.push_back(i);
			backtracking(k, n, i + 1);
			path.pop_back();
		}
	}

	void backtracking_01(int k, int n, int startidx, int sum)
	{
		if (sum > n) return;
		if (path.size() == k)
		{
			if (sum == n)
			{
				result.push_back(path);
			}
			return;
		}

		for (int i = startidx; i < 9; i++)
		{
			path.push_back(i);
			sum += i;
			backtracking_01(k, n, i + 1, sum);
			path.pop_back();
			sum -= i;
		}
	}
public:
	std::vector<vector<int>> combinationSum3(int k, int n) {
		backtracking_01(k, n, 1, 0);
		return result;
    }
};
