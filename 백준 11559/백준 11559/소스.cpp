#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define ROW 12
#define COL 6
using namespace std;

char mp[ROW][COL];
bool vs[ROW][COL];
bool bfs(int a, int b)
{
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	vs[a][b] = true;
	char save = mp[a][b];
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	vector<pair<int, int>> v;
	v.push_back(make_pair(a, b));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= ROW || ny < 0 || ny >= COL) continue;
			if (mp[nx][ny] == save && !vs[nx][ny]) {
				vs[nx][ny] = true;
				q.push(make_pair(nx, ny));
				v.push_back(make_pair(nx, ny));
			}
		}
	}
	if (v.size() < 4) return false;
	else {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			mp[x][y] = '.';
		}
		return true;
	}
}
void downdown()
{
	for (int i = ROW - 2; i >= 0; i--) {
		for (int j = 0; j < COL; j++) {
			if (mp[i][j] != '.' && mp[i + 1][j] == '.') {
				int k = i;
				while (k < ROW - 1 && mp[k + 1][j] == '.') k++;
				mp[k][j] = mp[i][j];
				mp[i][j] = '.';
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			cin >> mp[i][j];
	int ans = 0;
	while (1)
	{
		memset(vs, false, sizeof(vs));
		bool check=false;
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (mp[i][j] != '.' && !vs[i][j]) {
					if (bfs(i, j))
						check = true;
				}
			}
		}
		if (!check) break;
		downdown();
		ans++;
	}
	cout << ans;
}