#pragma once
#include <string>
using namespace std;
class Solution {
    //i�����, j���Ҳ�
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
         * ��̬�滮��̫���˲������
         * ʹ��˫ָ�뷨, �жϻ����ַ���, �����ҵ����ĵ�, Ȼ��ʹ��˫ָ����������ɢ�Ƚ�ֵ
         * ���� c a b a c, ����ÿһ��char, һ����������ĵ���һ��char, Ҳ���ǻ������������ַ�
         * һ����������ĵ��������ַ�, ������ż�����ַ�
         */
        for (int i = 0; i < s.size(); i++)
        {
            result += huiwen(i, i, s);
            result += huiwen(i, i+1, s);
        }
        
    	return result;
    }
};
