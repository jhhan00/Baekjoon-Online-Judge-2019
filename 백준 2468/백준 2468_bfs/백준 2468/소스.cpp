#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int mp[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int solve(int n, int xx) // bfsÀÌ¿ë
{
	bool visit[100][100];
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp[i][j] >= xx && visit[i][j] == false) {
				ans++;
				visit[i][j] = true;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
							if (visit[nx][ny] == false && mp[nx][ny] >= xx) {
								visit[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			if (mx < mp[i][j])
				mx = mp[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= mx; i++) {
		int aa = solve(n, i);
		if (ans < aa)
			ans = aa;
	}
	cout << ans << '\n';
}
