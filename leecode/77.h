#pragma once
#include <vector>
using namespace std;
class Solution {
	vector<int> path{};
	vector<vector<int>>  result{}; //ȫ�ֱ���
	void backtracking(int n, int k, int startidx) 
	{
		if (path.size() == k) //����k�������ֺ�, ������, ��ֹ
		{
			result.push_back(path);
			return;
		}
		for (int i = startidx; i <= n; i++)
		{
			path.push_back(i); //���i
			backtracking(n, k, i+1); //������ֵ
			path.pop_back();
		}
	}

public:
	std::vector<vector<int>> combine(int n, int k) {
		backtracking(n, k, 1);
		return result;
    }
};
