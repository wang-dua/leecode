#pragma once
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
/*
 *二者区别是 当出现未满足的情况下, 谁动
 *大饼干优先填满大胃口, 从末尾开始, 当未满足孩子时, 已经没有比当前尺寸更大的饼干了, 当满足时, 饼干才会向前, 所以for循环是孩子, 当满足时饼干向前移动
 */
public:

    //大饼干优先填满大胃口
    int findContentChildren(vector<int>& g, std::vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result{};
        int child_idx = g.size() - 1;
        int cookie_idx = s.size() - 1;
		for (; child_idx >= 0; child_idx--)
		{
            if (s[cookie_idx] >= g[child_idx] && cookie_idx >= 0){
                result++;
                cookie_idx--;
            }
		}
        return result;
        
    }

    //小饼干优先填满小胃口
    int findContentChildren_(vector<int>& g, std::vector<int>& s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result{};
        int child_idx{}, cookie_idx{};
        for (; cookie_idx < s.size(); cookie_idx++)
        {
	        if (child_idx == g.size()) break;
            if (s[cookie_idx] >= g[child_idx])
            {
                result++;
                child_idx++;
            }
        }
        return result;
        
    }
};
