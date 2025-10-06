#pragma once
#include <iostream>
#include <strstream>
#include <vector>

class Sort
{
public:
	std::vector<int> arr;
	
public:
/*
 * BubbleSort, 稳定,每一趟交换元素若干次, 每一趟最后将未排序的元素的最值移动到对应位置
 */
	void BubbleSort()
	{
		bool swapped; //判断排序提前结束

		int size = arr.size();
		for (int i  = 0; i < size-1; i++) //循环 size - 1 趟, 外层的i仅计数, 不作数组索引
		{
			swapped = false;
			for (int j = 0; j < size-1-i; j++)// 每一趟从头开始比较
			{ 
				if (arr[j] > arr[j+1])
				{
					std::swap(arr[j], arr[j + 1]);
					swapped = true;
				}
			}
			if (swapped == false)
			{
				break;
			}
		}
	}

/*
 * SelectSort, 选择排序, 选择最小的
 * 不稳定, 每一趟更新minidx索引若干次, 每一趟最后最多交换一次元素
 */ 
	void SelectSort()
	{
		int size = arr.size();
		for (int i = 0; i < size-1; i++) // 循环size-1趟, i是无序序列的第一个元素
		{
			int minidx = i;
			for (int j = i+1; j < size; j++) //内层循环只用于更新 mindix
			{
				if (arr[j] < arr[minidx])
				{
					minidx = j;
				}
			}
			if (i != minidx) //每一趟交换一次/也可能不交换元素
			{
				std::swap(arr[i], arr[minidx]);
			}
		}
	}

/*
 * InsertSort, 插入排序, 将元素插入到前面
 * 稳定, 每一趟移动相邻元素若干次, 每一趟只交换(填入)一次
 * 对于相对有序的序列, 插入排序更快
 */
	void InsertSort()
	{
		int size = arr.size();

		/*
		 * 0号元素是一个元素, 算有序序列, 所以i从1开始, 循环size-1趟
		 * 每次内循环取出无序序列序列的一个元素temp, 与前面的有序序列比较, 移动有序序列的元素
		 * 每一趟结束将temp 填入有序序列空出来的坑位置, 位置在j+1
		 */
		for (int i = 1; i < size; i++) //i从1到size-1
		{
			int temp = arr[i];
			int j = i - 1;
			for (; j >= 0; j--)
			{
				if (temp < arr[j])
				{
					arr[j + 1] = arr[j];
				}
			}
			arr[j + 1] = temp;
		}
	}

	/*
 *  ShellSort, 不稳定, 是基于插入排序的方法, 设置gap, gap逐渐缩小到1即为直接插入
 *  逻辑是和插入排序相同, 多了一层最外层的gap循环
 *  在移动元素时, 移动跨度是gap
 */
	void ShellSort()
	{
		int size = arr.size();
		for (int gap = size/2; gap >=1; gap /=2)
		{
			for (int i = 1; i < size; i += gap)
			{
				int temp = arr[i];
				int j = i - gap;
				for (; j >= 0; j -= gap)
				{
					if (arr[i] < arr[j])
					{
						arr[j + gap] = arr[j];
					}
				}
				arr[j + gap] = temp;
			}
		}
	}



	/*
 * QuickSort, 每一轮中, 会根据枢轴多次交换元素位置, 每一轮结束都会有元素放置在最终的排序位置
 * 不稳定
 */
	void QuickSort(int left, int right) //left, right是序列索引
	{

		int begin = left, end = right;
		if (begin >= end) return;

		int pivot = arr[(begin + end) / 2]; //保存值, 而不是索引
		while (begin <= end)
		{
			while (arr[begin] < pivot)
			{
				begin++;
			}
			while (arr[end] > pivot)
			{
				end--;
			}
			if (begin <= end)
			{
				std::swap(arr[begin], arr[end]);
				begin ++;
				end --;
			}
		}
		QuickSort(left, end);
		QuickSort(begin, right);
	}
};
