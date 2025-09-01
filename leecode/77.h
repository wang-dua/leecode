#pragma once
#include <vector>
using namespace std;
class Solution {
	vector<int> path{};
	vector<vector<int>>  result{}; //全局变量
	void backtracking(int n, int k, int startidx) 
	{
		if (path.size() == k) //当组k两个数字后, 保存结果, 终止
		{
			result.push_back(path);
			return;
		}
		for (int i = startidx; i <= n; i++)
		{
			path.push_back(i); //添加i
			backtracking(n, k, i+1); //深度添加值
			path.pop_back();
		}
	}

public:
	std::vector<vector<int>> combine(int n, int k) {
		backtracking(n, k, 1);
		return result;
    }
};
