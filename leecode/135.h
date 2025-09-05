#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int candy(std::vector<int>& ratings) {
        //0->0
        //1->1
        //2->2, 3
        if (ratings.size() < 2) return ratings.size();

        vector<int> candies(ratings.size(), 1);
        //´Ó×óµ½ÓÒ
        for (int i = 0; i < ratings.size() - 1; i++) 
        {
	        if (ratings[i + 1] > ratings[i])
                candies[i + 1] = candies[i] + 1;
        }

        for (int i = ratings.size() - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i])
                candies[i - 1] = candies[i] + 1;
        }
        int sum{};
        for (auto& n:candies)
        {
            sum += n;
        }
        return sum;
    }
};
