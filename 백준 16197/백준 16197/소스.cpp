#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int n, m;
char board[20][20];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int bf(int x1, int y1, int x2, int y2, int step)
{
	if (step > 10) return -1;
	bool f1 = false, f2 = false;
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) f1 = true;
	if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) f2 = true;
	if (f1&&f2) return -1;
	if (f1 || f2) return step;

	int ans = -1;
	for (int i = 0; i < 4; i++) {
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		
		if (nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m && board[nx1][ny1] == '#') {
			nx1 = x1;
			ny1 = y1;
		}
		if (nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m && board[nx2][ny2] == '#') {
			nx2 = x2;
			ny2 = y2;
		}
		int tmp = bf(nx1, ny1, nx2, ny2, step + 1);
		if (tmp == -1) continue;
		if (ans == -1 || ans > tmp)
			ans = tmp;
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int x[2], y[2];
	int z = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				x[z] = i; y[z] = j;
				z++;
			}
		}
	}
	cout << bf(x[0], y[0], x[1], y[1], 0) << "\n";
}