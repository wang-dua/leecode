#include<vector>
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return nums1;
        vector<int> record(1001, 0);
        unordered_set<int> resultSet;

        int i;
        for (i = 0; i < nums1.size(); i++)
        {
            record[nums1[i]]++;
        }
        for (i = 0; i < nums2.size(); i++)
        {
	        if (record[nums2[i]] != 0)
	        {
                resultSet.insert(nums2[i]);
	        }
        }
        return vector<int> (resultSet.begin(), resultSet.end());
    }
};

class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return nums1;
		unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> resultSet;
        for (int n: nums2)
        {
	        if (set1.find(n) != set1.end())
	        {
		        resultSet.insert(n);
	        }
        }
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};