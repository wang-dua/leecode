#pragma once
#include <vector>
using namespace std;
class Solution {
/*
 * ��300��ͬ����, ����Ҫ������, ����ֻ��ǰһ��Ԫ�رȽ��Ƶ�����
 * ��������̰�ķ�, ������� count++, С�� count=1�ж�, ��¼result
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
