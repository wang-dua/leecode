
#include "20.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	using namespace std;
	string str = "((()))[{()}]";
	Solution s;
	bool b = s.isValid(str);
	cout << b << "\n";
}
	