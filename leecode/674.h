#pragma once
#include <vector>
using namespace std;
class Solution {
/*
 * 和300不同的是, 本题要求连续, 所以只和前一个元素比较推导即可
 * 还可以用贪心法, 如果大于 count++, 小于 count=1中断, 记录result
 */
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            if (result < dp[i])
                result = dp[i];
        }
        return result;
    }
};
