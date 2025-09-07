#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*int main()
{
	int n, p, q;
	cin >> n >> p >> q;
	map <int, pair<vector<int>, vector<int>>> shoes{};

	for (int i = 0; i < n; i++)
	{
		int side, size, color;
		cin >> side >> size >> color;
		if (side == 0)
		{
			shoes[size].first.push_back(color);
		}
		else
		{
			shoes[size].second.push_back(color);
		}

	}

	int profit = 0;
	for (auto& [size, data]: shoes)
	{
		vector<int>& left_colors = data.first;
		vector<int>& right_colors = data.second;
		int pairs = min(left_colors.size(), right_colors.size());
		if (pairs == 0) continue;
		sort(left_colors.begin(), left_colors.end());
		sort(right_colors.begin(), right_colors.end());

		int same_color = 0;
		int i = 0, j = 0;

		while (i < left_colors.size() && j < right_colors.size())
		{
			if (left_colors[i] == right_colors[i])
			{
				same_color++;
				i++;
			}
			else if (left_colors[i] < right_colors[i])
			{
				i++;
			}
			else
			{
				j++;
			}
		}
		int diff_color = pairs - same_color;
		profit += same_color * p + diff_color * q;
	}
	cout << profit << endl;
	return 0;
}*/
