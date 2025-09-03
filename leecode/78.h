#pragma once
#include <vector>
using namespace std;
/*
 * �󼯺��Ӽ�, �����Ϻ������һ��, ��Ҫע��ռ�Ҳ���Ӽ�
 */
class Solution {
public:
    vector<int> path{};
    vector<vector<int>> result{};

    
    void backtracking(int startidx, vector<int>& nums)
    {
        result.push_back(path);
        if (startidx == nums.size()) return;

        for (int i = startidx; i <= nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();

        }
    }

    vector<vector<int>> subsets(std::vector<int>& nums) {
        backtracking(0, nums);
        return result;
    }
};
