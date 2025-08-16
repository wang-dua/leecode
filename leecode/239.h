#pragma once
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class MyQueue //����˫�˶���, һ�����, ���˳���ά����������, ��ͷ��Զ�����ֵ
{
public:
    deque<int> que;
	/*
	 * �����pop��������pop, Ҳ���ǻ�������ʹ�ø�Ԫ�ع���, ��Ԫ����Ŀǰ�����ֵ
	 * ����pop_front, push���pop�ǴӶ�β����
	 */
    void pop(int value)
    {
	    if (!que.empty() && value == que.front())
	    {
            que.pop_front();
	    }
    }

/*
 * ֻҪ��βB�ȵ�ǰ��Ҫ�����Ԫ��AС, ��B��A�������, ˵����A����ʱ, Bһ�����������ֵ,
 * ���Դ�ѭ����β������AС��Ԫ��, ��pop_back, �����pop, ��Ϊ��ά��������
 * ����Ԫ�غ���push��Ԫ��
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
        result.push_back(q.front()); //���Ƚ�ǰk��Ԫ��push, �����ֵ
/*
 *      �����鿪ͷ��ʼpop, �����ɻ������ھ����Ĺ���Ԫ��pop
 *      �ӻ���������һ��Ԫ�ؿ�ʼpush, push�����һ������Ԫ�ؽ���
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