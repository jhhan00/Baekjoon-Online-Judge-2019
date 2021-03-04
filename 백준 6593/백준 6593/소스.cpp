#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

char mp[30][30][30];
int visit[30][30][30];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
int bfs(int l, int r, int c, int h1, int h2, int h3, int e1, int e2, int e3)
{
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(h1, h2, h3));
	visit[h3][h1][h2] = 0;
	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		if (x == e1 && y == e2 && z == e3)
			return visit[z][x][y];
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
			if (mp[nz][nx][ny] == '#' || visit[nz][nx][ny] != -1) continue;
			visit[nz][nx][ny] = visit[z][x][y] + 1;
			q.push(make_tuple(nx, ny, nz));
		}
	}
	return -1;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int l, r, c;
	int hx, hy, hz, ex, ey, ez;
	while (1)
	{
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;
		for (int k = 0; k < l; k++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cin >> mp[k][i][j];
					if (mp[k][i][j] == 'S') {
						hz = k;
						hx = i;
						hy = j;						
					}
					if (mp[k][i][j] == 'E') {
						ez = k;
						ex = i;
						ey = j;
					}
				}
			}
		}
		memset(visit, -1, sizeof(visit));
		int ans = bfs(l, r, c, hx, hy, hz, ex, ey, ez);
		if (ans == -1)
			cout << "Trapped!" << '\n';
		else
			cout << "Escaped in " << ans << " minute(s)." << '\n';

	}
}