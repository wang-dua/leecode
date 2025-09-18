#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, std::vector<int>& nums2)
    {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == nums2[0]) dp[i][0] = 1; //初始化列
        }
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[0] == nums2[j]) dp[0][j] = 1;//初始化行
        }
        int result{};
        //从0开始遍历, 因为result要收集长度, 
        for (int i = 0; i < nums1.size(); i++)
        {
	        for (int j = 0; j < nums2.size(); j++)
	        {
		        if (nums1[i] == nums2[j] && i > 0 && j > 0)
		        {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
		        }
                result = dp[i][j] > result ? dp[i][j] : result;
	        }
        }
        return  result;
    }
};
