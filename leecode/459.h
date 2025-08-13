#pragma once
#include <string>
using std::string;

//暴力
class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        //重复子串拼接成主串, 那么子串一定是从0开始
        //所以只需要检查子串的结尾位置
        //如果主串长度不能整除子串, 是无法拼接的
		//整除, 就直接取出子串
        //将子串重复, 判断是否可以拼接为主串

        for (int len = 1; len <= s.size() / 2; len++)
        {
	        if (s.size() % len != 0)
                continue;
            string str = s.substr(0, len);
            string repeated;
            int count = s.size() / len;
            for (int i = 0; i < count; i++)
            {
                repeated += str;
            }
            if (repeated == s)
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool repeatedSubstringPattern(string s) {

    }
};