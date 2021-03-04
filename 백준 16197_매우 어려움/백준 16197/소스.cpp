#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int n, m;
char board[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int solve(int x1, int y1, int x2, int y2, int next)
{
	if (next > 10)
		return -1;
	bool fall1 = false, fall2 = false;
	if (x1<1 || x1>n || y1<1 || y1>m) fall1 = true;
	if (x2<1 || x2>n || y2<1 || y2>m) fall2 = true;
	if (fall1 && fall2) return -1;
	if (fall1 || fall2) return next;
	int ans = -1;
	for (int i = 0; i < 4; i++) {
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		if (nx1 > 0 && nx1 <= n && ny1 > 0 && ny1 <= m && board[nx1][ny1] == '#') {
			nx1 = x1; ny1 = y1;
		}
		if (nx2 > 0 && nx2 <= n && ny2 > 0 && ny2 <= m && board[nx2][ny2] == '#') {
			nx2 = x2; ny2 = y2;
		}
		int tmp = solve(nx1, ny1, nx2, ny2, next + 1);
		if (tmp == -1) continue;
		if (ans == -1 || ans > tmp)
			ans = tmp;
	}
	return ans;
}

int main()
{
	int x[2], y[2];
	int a = 0;
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				x[a] = i; y[a] = j;
				a++;
			}
		}
	}
	cout << solve(x[0], y[0], x[1], y[1], 0) << "\n";
}