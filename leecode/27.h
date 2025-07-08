#pragma once
#include <vector>
#include <iostream>
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
	        if (nums[i] == val)
	        {
                for (int j = i + 1; j < size; j++)
                    nums[j - 1] = nums[j];
                i--;
                size--;
	        }
        }
        return size;
    }
};

class Solution1 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int curr = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
	        if (nums[fast] != val) //fast指向不是val, pval会一起动, 否则pval就先停止
	        {
                nums[curr] = nums[fast];
                curr++;
	        }// 
        }
        return curr;
    }
};