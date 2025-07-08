
#include "151.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	using namespace std;
	Solution1 s;
	string str{ "   wang jia xuan is a    good   guy!   " };
	auto words = s.reverseWords(str);
	cout << words;
	cout << "\n";
}
	