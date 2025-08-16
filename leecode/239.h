#pragma once
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class MyQueue //利用双端队列, 一端入队, 两端出队维护单调队列, 队头永远是最大值
{
public:
    deque<int> que;
	/*
	 * 这里的pop是真正的pop, 也就是滑动窗口使得该元素过期, 该元素是目前的最大值
	 * 并且pop_front, push里的pop是从队尾弹出
	 */
    void pop(int value)
    {
	    if (!que.empty() && value == que.front())
	    {
            que.pop_front();
	    }
    }

/*
 * 只要队尾B比当前想要加入的元素A小, 而B比A更早过期, 说明当A存在时, B一定不会是最大值,
 * 所以从循环队尾弹出比A小的元素, 是pop_back, 这里的pop, 是为了维护单调性
 * 弹出元素后再push新元素
 */
    void push(int value)
    {
	    while (!que.empty() && value > que.back())
	    {
            que.pop_back();
	    }
        que.push_back(value);
    }
    int front() const
    {
        return que.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue q;
        for (int i = 0; i < k; i++)
        {
            q.push(nums[i]);
        }
        result.push_back(q.front()); //首先将前k个元素push, 求出最值
/*
 *      从数组开头开始pop, 这是由滑动窗口决定的过期元素pop
 *      从滑动窗口下一个元素开始push, push到最后一个数组元素结束
 */
        for (int i = k; i < nums.size(); i++)
        {
            q.pop(nums[i-k]);
            q.push(nums[i]);
            result.push_back(q.front());
        }
        return result;
    }
};









class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //queue<int> q; 9 6 9 3 8
        vector<int> result;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            int maxn = nums[i];
            for (int j = i; j <= i + k - 1; j++)
            {
                maxn = maxn >= nums[j] ? maxn : nums[j];
            }
            result.push_back(maxn);
        }
        return result;
    }
};