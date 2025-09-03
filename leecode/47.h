#pragma once
#include <algorithm>
#include <vector>
using namespace std;
class Solution {

	vector<int> path{};
	vector<vector<int>> result{};

	void backtracking(vector<bool>& used, vector<int>& nums)
	{
		if (path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (used[i] == true) continue; //ȷ��ͬ��λ�õ���ͬԪ�ز��ظ�
			if (i > 0 && nums[i - 1] == nums[i] && used[i-1] == false) continue; //ȷ��ͬһ�㲻�ظ�
			path.push_back(nums[i]);
			used[i] = true;
			backtracking(used, nums);
			path.pop_back();
			used[i] = false;
		}
	}
public:
	std::vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		backtracking(used, nums);
		return result;
    }
};
