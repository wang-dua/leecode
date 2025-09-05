#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        if (nums.size() < 2) return nums.size(); //

        // up �� down��������, �������ܱ�֤ƽ��, �����µĸ���, ��ס����
        int up = 1, down = 1;

        for (int i = 1; i < nums.size(); i++)
        {
	        if (nums[i] - nums[i - 1] > 0)
	        {
                up = down + 1;
	        }
	        else if (nums[i] - nums[i - 1] < 0)
	        {
                down = up + 1;
	        }
        }
        return max(up, down);
        
    }
};
