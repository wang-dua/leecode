#pragma once
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
            if (used[i] == true) continue; //同一个路径(树枝)中, 不能有重复的
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(used, nums);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<std::vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(used, nums);
        return result;
    }
};
