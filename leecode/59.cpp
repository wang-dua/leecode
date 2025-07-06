#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int startx = 0;
		int starty = 0;
		int loop = n / 2; // ѭ����Ȧ��, ���n������, �м��ֵ��Ҫ��������
		int mid = n / 2;  // nΪ����ʱ���ĵ�λ��
		int count = 1;
		int offset = 1; // ����ÿһ��/��ѭ���Ĵ���, ����һȦoffset++
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;

			// ÿһ����/�ж���ѭ����ҿ���ѭ��ԭ��, �������ܱ�֤ѭ������һ����

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