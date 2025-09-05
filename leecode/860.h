#pragma once
#include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        int five_num = 0;
        int ten_num = 0;
        for (auto& n : bills)
        {
	        if (n == 5)
	        {
                five_num++;
	        }
	        else if (n == 10)
	        {
                if (five_num <= 0) return false;
                ten_num++;
                five_num--;
	        }
	        else
	        {
		        if (ten_num > 0 && five_num > 0)
		        {
					ten_num--;
					five_num--;
		        }
		        else if (five_num >= 3)
		        {
					five_num -= 3;
		        }
				else
				{
					return false;
				}
	        }
        }
		return true;
    }
};