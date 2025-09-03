#pragma once
#include <algorithm>
#include <vector>
using namespace std;
/*
 * candidates�п������ظ�ֵ, ͬһ·���������ظ�ֵ, �������ͬһ��ѡ����֮ǰ�ù�������, ��ô���ϻ��ظ�, ������forѭ��ʱ, Ҫȥ����ǰ�ù���Ԫ��
 */
class Solution {
public:
	vector<int> path{};
	vector<vector<int>> result{};
	void backtracking(vector<int>& candidates, int target, int sum, int startidx, vector<bool>& used)
	{
		if (sum > target) return;
		if (sum == target)
		{
			result.push_back(path);
			return;
		}

		for (int i = startidx; i < candidates.size(); i++)
		{
			if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
				continue;

			path.push_back(candidates[i]);
			used[i] = true;
			sum += candidates[i];
			backtracking(candidates, target, sum, i + 1, used);
			path.pop_back();
			used[i] = false;
			sum -= candidates[i];
		}
	}

	std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
		vector<bool> used(candidates.size());
		sort(candidates.begin(), candidates.end()); //����
		backtracking(candidates, target, 0, 0, used);
		return result;
    }
};
