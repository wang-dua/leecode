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
	//删除str的前后空格, 添加了单词之间的空格
	void deleteSpaces(std::string& s)
	{
		//使用双指针删除前后空格, 在单词之间添加空格
		//翻转整个字符串
		//依照空格隔开翻转每个单词, 做到了原地处理, 且时间复杂度为o(n)
		int slow = 0;
		for (int fast = 0; fast < s.size(); fast++)
		{
			// 这里的slow和fast是字母的索引, 所以在使用快慢指针挪动的时候要获取整个单词, 而不是字母
			//使用快慢指针删除了所有空格, 但是我们手动添加了单词之间的空格
			if (s[fast] != ' ')
			{
				//每一轮循环中, slow的跨度的单词(或者不动)
				if (slow != 0) 
					//在快慢指针的基础上添加的新东西: 在单词之间添加新空格, slow++会跨过新空格, 
					s[slow++] = ' ';
				//移动元素不再是按照单个索引而是单词
				while (fast < s.size() && s[fast] != ' ')
				{
					s[slow] = s[fast];
					slow++;
					fast++;
				}
			}
		}
		s.resize(slow); //slow 在有效元素的后面一位
	}
	void reverseStr(std::string& s, int start, int end)
	{
		for (; start <= end; start++, end--)
			std::swap(s[start], s[end]);
	}
	
};