#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char mp[50][50];
bool visited[50][50];
int time[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m;
int bfs(int a, int b)
{
	int rt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visited[a][b] = true;
	time[a][b] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (mp[nx][ny] == 'L' && visited[nx][ny] == false && time[nx][ny] == -1) {
				visited[nx][ny] = true;
				time[nx][ny] = time[x][y] + 1;
				q.push(make_pair(nx, ny));
				if (rt < time[nx][ny])
					rt = time[nx][ny];
			}
		}
	}
	return rt;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mp[i][j];
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				memset(time, -1, sizeof(time));
				int tmp = bfs(i, j);
				if (mx < tmp)
					mx = tmp;
			}
		}
	}
	cout << mx << '\n';
}