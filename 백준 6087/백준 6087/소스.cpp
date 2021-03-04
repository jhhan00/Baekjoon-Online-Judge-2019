#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

char mp[100][100];
int mr[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void bfs(int a, int b, int m, int n);
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, i, j;
	int clx[2], cly[2];
	int a = 0;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == '*')
				mr[i][j] = -2;
			else {
				mr[i][j] = -1;
				if (mp[i][j] == 'C') {
					clx[a] = i; cly[a] = j;
					a++;
				}
			}
		}
	}
	bfs(clx[0], cly[0], m, n);
	cout << mr[clx[1]][cly[1]]-1 << '\n';
}
void bfs(int a, int b, int m, int n)
{
	queue<int> qx; queue<int> qy;
	qx.push(a); qy.push(b);
	mr[a][b] = 0;
	while (!qx.empty() && !qy.empty())
	{
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (mr[nx][ny] == -2) break;
				if (mr[nx][ny] == -1) {
					mr[nx][ny] = mr[x][y] + 1;
					qx.push(nx); qy.push(ny);
				}
				nx += dx[i]; ny += dy[i];
			}
		}
	}
}