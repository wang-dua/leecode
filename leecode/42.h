#pragma once
#include <vector>
using namespace std;
class Solution {
public:
    int trap(std::vector<int>& height) {
        int sum{};
        for (int i = 1; i < height.size()-1; i++)
        {
            int lheight, rheight = height[i];
            for (int j=i-1; j >= 0; j--)
            {
                lheight = max(lheight, height[j]);
            }
            for (int k = i + 1; k < height.size(); k++)
            {
                rheight = max(rheight, height[k]);
            }
            int h = min(lheight, rheight);
            if (h > 0)
            {
                sum += h;
            }
        }
        return sum;
    }
};
