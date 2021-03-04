#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int nn;
	cin >> nn;
	long li[6];
	int ans;
	for (int i = 0; i < nn; i++) {
		long sq[4][2];
		for (int j = 0; j < 4; j++)
			cin >> sq[j][0] >> sq[j][1];
		li[0] = (sq[1][0] - sq[0][0])*(sq[1][0] - sq[0][0]) + (sq[1][1] - sq[0][1])*(sq[1][1] - sq[0][1]);
		li[1] = (sq[2][0] - sq[1][0])*(sq[2][0] - sq[1][0]) + (sq[2][1] - sq[1][1])*(sq[2][1] - sq[1][1]);
		li[2] = (sq[3][0] - sq[2][0])*(sq[3][0] - sq[2][0]) + (sq[3][1] - sq[2][1])*(sq[3][1] - sq[2][1]);
		li[3] = (sq[0][0] - sq[3][0])*(sq[0][0] - sq[3][0]) + (sq[0][1] - sq[3][1])*(sq[0][1] - sq[3][1]);
		li[4] = (sq[0][0] - sq[2][0])*(sq[0][0] - sq[2][0]) + (sq[0][1] - sq[2][1])*(sq[0][1] - sq[2][1]);
		li[5] = (sq[1][0] - sq[3][0])*(sq[1][0] - sq[3][0]) + (sq[1][1] - sq[3][1])*(sq[1][1] - sq[3][1]);
		/*
		for (int j = 1; j < 6; j++) {
			int val = li[j];
			int a = j;
			while (li[a - 1] > val) {
				li[a] = li[a - 1];
				a--;
			}
			li[a] = val;
		}*/
		sort(li, li+6);

		if (li[0] == li[1] && li[1] == li[2] && li[2] == li[3] && li[4] == li[5])
			ans = 1;
		else ans = 0;
		cout << ans << endl;
	}
}