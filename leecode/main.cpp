#include "Sort.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;



int main()
{
	Sort s;
	srand(time(0));
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.emplace_back(rand() % 100);
	}

	cout << "origin: \n";
	for (int i : vec) cout << i << " ";

	cout << "\n";

	s.arr = vec;
	//s.BubbleSort();
	//s.SelectSort();
	//s.InsertSort();
	s.QuickSort(0, s.arr.size()-1);
	cout << "Sorted:\n";
	for (int i : s.arr) cout << i << " ";
	cout << "\n";
}