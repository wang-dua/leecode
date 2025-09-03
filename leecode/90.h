#pragma once
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 数组有重复元素, 求子集
 * 和之前做的数组求和为target的题目类似
 */
class Solution {

    vector<int> path{};
    vector<vector<int>> result{};
    void backtracking(int startidx, vector<int>& nums, vector<bool>& used)
    {
        result.push_back(path);
        if (startidx == nums.size()) return;

        for (int i = startidx; i < nums.size(); i++)
        {
	        if (i > 0 && nums[i] == nums[i-1] && used[i - 1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(i + 1, nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size());
        backtracking(0, nums, used);
        return result;
    }
};
