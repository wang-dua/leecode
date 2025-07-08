#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
class Solution
{
public:
	std::string reverseWords(std::string s)
	{
		std::istringstream ss(s);
		std::string word;
		std::vector<std::string> strVector;
		std::string reversStr;
		while (ss >> word)
		{
			strVector.push_back(word);
		}
		for (int i = static_cast<int>(strVector.size()) - 1; i >= 0; i--)
		{
			reversStr += strVector[i];
			if (i > 0)
				reversStr += " ";
		}
		return reversStr;
	}
};

class Solution1
{
public:
	std::string reverseWords(std::string s)
	{
		deleteSpaces(s);
		reverseStr(s, 0, s.size() - 1);
		int start = 0;
		for (int i = 0; i <= s.size(); i++)
		{
			if (i == s.size() || s[i] == ' ')
			{
				reverseStr(s, start, i - 1);
				start = i + 1;
			}
		}
		return s;
	}
	//ɾ��str��ǰ��ո�, ����˵���֮��Ŀո�
	void deleteSpaces(std::string& s)
	{
		//ʹ��˫ָ��ɾ��ǰ��ո�, �ڵ���֮����ӿո�
		//��ת�����ַ���
		//���տո������תÿ������, ������ԭ�ش���, ��ʱ�临�Ӷ�Ϊo(n)
		int slow = 0;
		for (int fast = 0; fast < s.size(); fast++)
		{
			// �����slow��fast����ĸ������, ������ʹ�ÿ���ָ��Ų����ʱ��Ҫ��ȡ��������, ��������ĸ
			//ʹ�ÿ���ָ��ɾ�������пո�, ���������ֶ�����˵���֮��Ŀո�
			if (s[fast] != ' ')
			{
				//ÿһ��ѭ����, slow�Ŀ�ȵĵ���(���߲���)
				if (slow != 0) 
					//�ڿ���ָ��Ļ�������ӵ��¶���: �ڵ���֮������¿ո�, slow++�����¿ո�, 
					s[slow++] = ' ';
				//�ƶ�Ԫ�ز����ǰ��յ����������ǵ���
				while (fast < s.size() && s[fast] != ' ')
				{
					s[slow] = s[fast];
					slow++;
					fast++;
				}
			}
		}
		s.resize(slow); //slow ����ЧԪ�صĺ���һλ
	}
	void reverseStr(std::string& s, int start, int end)
	{
		for (; start <= end; start++, end--)
			std::swap(s[start], s[end]);
	}
	
};