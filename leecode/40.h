#pragma once
#include <algorithm>
#include <vector>
using namespace std;
/*
 * candidates中可能有重复值, 同一路径可以有重复值, 但是如果同一层选用了之前用过的数字, 那么集合会重复, 所以在for循环时, 要去除先前用过的元素
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
		sort(candidates.begin(), candidates.end()); //排序
		backtracking(candidates, target, 0, 0, used);
		return result;
    }
};
