#pragma once
#include <string>
using std::string;

//����
class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        //�ظ��Ӵ�ƴ�ӳ�����, ��ô�Ӵ�һ���Ǵ�0��ʼ
        //����ֻ��Ҫ����Ӵ��Ľ�βλ��
        //����������Ȳ��������Ӵ�, ���޷�ƴ�ӵ�
		//����, ��ֱ��ȡ���Ӵ�
        //���Ӵ��ظ�, �ж��Ƿ����ƴ��Ϊ����

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