#pragma once
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

/**
 * 使用map可以统计 值:出现频次 key:value, map仅对key进行排序, 无法输出前k个高频元素
 * 可以使用 k节点小顶堆 (使用优先级队列实现): 父节点比左右节点都要小, push元素后, 从根节点pop出最小的元素
 * 遍历结束后, 留下前k个高频元素
 */
class mycomparison
{
public:
	bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
	{
		return lhs.second > rhs.second; //map中的second是出现频次
	}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map; //map存放 数组值:出现次数
		for (int i = 0; i < nums.size(); i++)
		{
			map[nums[i]]++;
		}

		//priority_queue 是优先级队列, 自动在队列中排序, 接口跟队列相同
		//默认是大顶堆, 提供可调用函数对象 mycomparision 变为小顶堆
		//小顶堆存放pair, 按出现次数进行排序
		//小顶堆的元素个数由用户自己维护
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




