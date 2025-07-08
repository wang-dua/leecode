
#include "1.h"
#include <iostream>
#include <vector>

int main()
{
	using namespace std;
	Solution1 s;
	vector<int> nums{3, 3};
	int target = 6;
	auto v = s.twoSum(nums, target);
	for (auto ele : v)
		cout << ele << " ";
	cout << "\n";
	return 0;
}