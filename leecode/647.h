#pragma once
#include <string>
using namespace std;
class Solution {
    //i是左侧, j是右侧
    int huiwen(int i, int j, string s)
    {
        int res{};
	    while (i >= 0 && j < s.size() && s[i] == s[j])
	    {
            i--;
            j++;
            res++;
	    }
        return res;
    }

public:
    int countSubstrings(string s) {
		int result{};
        /*
         * 动态规划法太难了不好理解
         * 使用双指针法, 判断回文字符串, 可以找到中心点, 然后使用双指针向两侧扩散比较值
         * 对于 c a b a c, 遍历每一个char, 一种情况是中心点是一个char, 也就是回文是奇数个字符
         * 一种情况是中心点是两个字符, 回文是偶数个字符
         */
        for (int i = 0; i < s.size(); i++)
        {
            result += huiwen(i, i, s);
            result += huiwen(i, i+1, s);
        }
        
    	return result;
    }
};
