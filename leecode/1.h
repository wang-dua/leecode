#pragma once
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	std::vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> numToIndex;
		for (int i = 0; i < nums.size(); i++)
		{
			int n = nums[i];
			auto it2 = numToIndex.find(target - n);
			if (it2 != numToIndex.end())
				return { i, it2->second };
			numToIndex[n] = i;
		}
		
		return {};
    }
};

class Solution1 {
public:
	std::vector<int> twoSum(vector<int>& nums, int target) {
		multimap<int, int> numsToIndex;
		for (int i = 0; i < nums.size(); i++)
		{
			numsToIndex.insert(pair<int, int>{nums[i], i});
		}
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = numsToIndex.find(target - nums[i]);
			if (it != numsToIndex.end())
				return { i, it->second };
		}
		return {};
	}
};