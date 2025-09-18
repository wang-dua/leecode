#include "718.h"
#include <iostream>
#include <vector>
using namespace std;



int main()
{
	Solution s;
	vector<int> A = {70, 39, 25, 40, 52};
	vector<int> B = {52, 20, 67, 5, 31};

	int n = s.findLength(A, B);
	cout << n << endl;
}