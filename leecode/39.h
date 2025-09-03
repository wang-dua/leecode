#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> path{};
    vector<vector<int>> result{};

    void backtracking(vector<int>& candidates, int target, int sum, int startidx)
    {
    	if (sum > target) return;
        if (sum == target)
        {
	        result.push_back(path);
        	return;
        }


        for (int i = startidx; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i);
            path.pop_back();
            sum -=candidates[i];
        }
    }

    vector<std::vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
