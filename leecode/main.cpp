
#include "150.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	using namespace std;
	Solution s;
	vector<string> tokens{ "1", "2", "+", "3", "4", "+", "*" };
	int result = s.evalRPN(tokens);
	cout << result << "\n";
}
	