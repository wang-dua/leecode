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
 * BubbleSort, �ȶ�,ÿһ�˽���Ԫ�����ɴ�, ÿһ�����δ�����Ԫ�ص���ֵ�ƶ�����Ӧλ��
 */
	void BubbleSort()
	{
		bool swapped; //�ж�������ǰ����

		int size = arr.size();
		for (int i  = 0; i < size-1; i++) //ѭ�� size - 1 ��, ����i������, ������������
		{
			swapped = false;
			for (int j = 0; j < size-1-i; j++)// ÿһ�˴�ͷ��ʼ�Ƚ�
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
 * SelectSort, ѡ������, ѡ����С��
 * ���ȶ�, ÿһ�˸���minidx�������ɴ�, ÿһ�������ཻ��һ��Ԫ��
 */ 
	void SelectSort()
	{
		int size = arr.size();
		for (int i = 0; i < size-1; i++) // ѭ��size-1��, i���������еĵ�һ��Ԫ��
		{
			int minidx = i;
			for (int j = i+1; j < size; j++) //�ڲ�ѭ��ֻ���ڸ��� mindix
			{
				if (arr[j] < arr[minidx])
				{
					minidx = j;
				}
			}
			if (i != minidx) //ÿһ�˽���һ��/Ҳ���ܲ�����Ԫ��
			{
				std::swap(arr[i], arr[minidx]);
			}
		}
	}

/*
 * InsertSort, ��������, ��Ԫ�ز��뵽ǰ��
 * �ȶ�, ÿһ���ƶ�����Ԫ�����ɴ�, ÿһ��ֻ����(����)һ��
 * ����������������, �����������
 */
	void InsertSort()
	{
		int size = arr.size();

		/*
		 * 0��Ԫ����һ��Ԫ��, ����������, ����i��1��ʼ, ѭ��size-1��
		 * ÿ����ѭ��ȡ�������������е�һ��Ԫ��temp, ��ǰ����������бȽ�, �ƶ��������е�Ԫ��
		 * ÿһ�˽�����temp �����������пճ����Ŀ�λ��, λ����j+1
		 */
		for (int i = 1; i < size; i++) //i��1��size-1
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
 *  ShellSort, ���ȶ�, �ǻ��ڲ�������ķ���, ����gap, gap����С��1��Ϊֱ�Ӳ���
 *  �߼��ǺͲ���������ͬ, ����һ��������gapѭ��
 *  ���ƶ�Ԫ��ʱ, �ƶ������gap
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
 * QuickSort, ÿһ����, ����������ν���Ԫ��λ��, ÿһ�ֽ���������Ԫ�ط��������յ�����λ��
 * ���ȶ�
 */
	void QuickSort(int left, int right) //left, right����������
	{

		int begin = left, end = right;
		if (begin >= end) return;

		int pivot = arr[(begin + end) / 2]; //����ֵ, ����������
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
