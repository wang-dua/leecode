#pragma once
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
/*
 *���������� ������δ����������, ˭��
 *���������������θ��, ��ĩβ��ʼ, ��δ���㺢��ʱ, �Ѿ�û�бȵ�ǰ�ߴ����ı�����, ������ʱ, ���ɲŻ���ǰ, ����forѭ���Ǻ���, ������ʱ������ǰ�ƶ�
 */
public:

    //���������������θ��
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

    //С������������Сθ��
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
