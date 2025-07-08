#pragma once
#include <vector>
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            std::swap(s[i], s[j]);
        }
    }
};