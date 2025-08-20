#pragma once
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

/**
 * ʹ��map����ͳ�� ֵ:����Ƶ�� key:value, map����key��������, �޷����ǰk����ƵԪ��
 * ����ʹ�� k�ڵ�С���� (ʹ�����ȼ�����ʵ��): ���ڵ�����ҽڵ㶼ҪС, pushԪ�غ�, �Ӹ��ڵ�pop����С��Ԫ��
 * ����������, ����ǰk����ƵԪ��
 */
class mycomparison
{
public:
	bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
	{
		return lhs.second > rhs.second; //map�е�second�ǳ���Ƶ��
	}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map; //map��� ����ֵ:���ִ���
		for (int i = 0; i < nums.size(); i++)
		{
			map[nums[i]]++;
		}

		//priority_queue �����ȼ�����, �Զ��ڶ���������, �ӿڸ�������ͬ
		//Ĭ���Ǵ󶥶�, �ṩ�ɵ��ú������� mycomparision ��ΪС����
		//С���Ѵ��pair, �����ִ�����������
		//С���ѵ�Ԫ�ظ������û��Լ�ά��
		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
		for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			pri_que.push(*it);
			if (pri_que.size() > k)
			{
				pri_que.pop();
			}
		}

		vector<int> result;
		for (int i = 0; i < k; i++)
		{
			result.insert(result.begin(), pri_que.top().first);
			pri_que.pop();
		}

		return result;
    }
};




