#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<pair<int, int>> qf;
queue<pair<int, int>> qj;
int visitfire[1000][1000];
int visitjj[1000][1000];
char mp[1000][1000];
int Escape(int r, int c)
{
	while (!qj.empty())
	{
		int x = qj.front().first;
		int y = qj.front().second;
		qj.pop();
		if (x == 0 || x == r - 1 || y == 0 || y == c - 1)
			return visitjj[x][y]+1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (mp[nx][ny] == '#' || visitjj[nx][ny] != -1) continue;
			if (visitfire[nx][ny] > visitjj[x][y] + 1 || visitfire[nx][ny] == -1) {
				// 불이 번진 곳보다 빨리 도착하는 경우와
				// 불이 아예 없는 경우도 고려해야 한다
				visitjj[nx][ny] = visitjj[x][y] + 1;
				qj.push(make_pair(nx, ny));
			}
		}
	}
	return -1;
}
void Fire(int r, int c)
{
	while (!qf.empty())
	{
		int x = qf.front().first;
		int y = qf.front().second;
		qf.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (mp[nx][ny] == '#' || visitfire[nx][ny] != -1) continue;
			visitfire[nx][ny] = visitfire[x][y] + 1;
			qf.push(make_pair(nx, ny));
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r,c;
	cin >> r >> c;
	memset(visitfire, -1, sizeof(visitfire));
	memset(visitjj, -1, sizeof(visitjj));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'J') {
				qj.push(make_pair(i, j));
				visitjj[i][j] = 0;
			}
			if (mp[i][j] == 'F') {
				qf.push(make_pair(i, j));
				visitfire[i][j] = 0;
			}
		}
	}
	Fire(r, c);
	int ans = Escape(r, c);
	if (ans == -1) cout << "IMPOSSIBLE" << "\n";
	else cout << ans << "\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << visitfire[i][j] << ' ';
		cout << endl;
	}cout << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << visitjj[i][j] << ' ';
		cout << endl;
	}
}