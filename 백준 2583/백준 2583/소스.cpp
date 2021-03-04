#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int mp[101][101];
int visit[101][101];
int bfs(int n, int m, int a, int b)
{
	int cnt = 1;
	visit[a][b] = cnt;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (mp[nx][ny] == 0 && visit[nx][ny] == -1) {
				visit[nx][ny] = cnt + 1;
				q.push(make_pair(nx, ny));
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> m >> n >> k;
	while (k--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				mp[i][j] = 1;
	}
	memset(visit, -1, sizeof(visit));
	vector<int> v;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 0 && visit[i][j] == -1) {
				ans++;
				int tmp = bfs(n, m, i, j);
				v.push_back(tmp);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << ans << endl;
	for (int k = 0; k < v.size(); k++)
		cout << v[k] << ' ';
}