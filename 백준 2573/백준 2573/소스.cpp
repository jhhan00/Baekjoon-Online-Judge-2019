#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int ice[300][300];
bool visited[300][300];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool melted()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ice[i][j] != 0)
				return false;
	return true;
}
void melting()
{
	int tmp[300][300];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = ice[i][j];
			if (tmp[i][j]) {
				for (int k = 0; k < 4; k++) {
					if (tmp[i][j] == 0) break;
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ice[ni][nj] == 0) tmp[i][j]--;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ice[i][j] = tmp[i][j];
}
void bfs(int a, int b)
{
	visited[a][b] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == false && ice[nx][ny] > 0) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ice[i][j];
	int year = 0;
	while (!melted()) {
		melting(); year++;
		memset(visited, false, sizeof(visited));
		int icecount = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] && visited[i][j] == false) {
					icecount++;
					bfs(i, j);
				}
			}
		}
		if (icecount >= 2) {
			cout << year << '\n';
			return 0;
		}
	}
	cout << 0 << endl;
}