#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int startx = 0;
		int starty = 0;
		int loop = n / 2; // 循环的圈数, 如果n是奇数, 中间的值需要单独处理
		int mid = n / 2;  // n为奇数时中心的位置
		int count = 1;
		int offset = 1; // 控制每一行/列循环的次数, 深入一圈offset++
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;

			// 每一个行/列都遵循左闭右开的循环原则, 这样才能保证循环条件一致性

			for (j; j < n - offset; j++) {
				res[i][j] = count++;
			}
			for (i; i < n - offset; i++) {
				res[i][j] = count++;
			}
			for (j; j > offset - 1; j--) {
				res[i][j] = count++;
			}
			for (i; i > offset - 1; i--) {
				res[i][j] = count++;
			}
			offset++;
			startx++;
			starty++;
		}
		if (n % 2) {
			res[mid][mid] = count;
		}
		return res;
	}
};