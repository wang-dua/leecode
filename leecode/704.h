#pragma once
#include <inttypes.h>
#include <vector>
using namespace std;
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target)
            {
                low++;
            }
            else
            {
                high++;
            }
        }
        return -1;
    }
};
