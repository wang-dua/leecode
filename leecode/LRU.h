#pragma once
#include <list>
#include <unordered_map>

class LRU
{
private:
	using li = std::list<std::pair<int, int>>;
	int capacity;
	li CacheList;
	std::unordered_map<int, li::iterator> nodeMap;
public:
	LRU() = default;
	LRU(int v): capacity(v){}

	int get(int key)
	{
		auto it = nodeMap.find(key);
		if (it == nodeMap.end()) return -1;//没有找到
		CacheList.splice(CacheList.begin(), CacheList, it->second);//找到了, 放前面
		return it->second->second;
	}

	void put(int key, int val)
	{
		auto it = nodeMap.find(key);
		if (it != nodeMap.end())
		{
			it->second->second = val;
			CacheList.splice(CacheList.begin(), CacheList, it->second);
			return;
		}

		if (nodeMap.size() == capacity)
		{
			auto deleteIt = CacheList.back();
			CacheList.pop_back();
			nodeMap.erase(deleteIt.first);
		}
		CacheList.emplace_front(key, val);
		nodeMap[key] = CacheList.begin();
	}
};
