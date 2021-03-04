#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char building[1000][1000];
int fire[1000][1000];
int run[1000][1000];
void bfs_fire(queue<pair<int, int>> &q, int h, int w)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (building[i][j] == '*')
				fire[i][j] = 0;
			else
				fire[i][j] = -1;
		}
	}
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (building[nx][ny] == '#') continue;
			if (fire[nx][ny] == -1) {
				q.push(make_pair(nx, ny));
				fire[nx][ny] = fire[x][y] + 1;
			}
		}
	}
}
void bfs_human(int a, int b, int h, int w)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (building[i][j] == '@')
				run[i][j] = 0;
			else
				run[i][j] = -1;
		}
	}

	queue<pair<int, int>> qh;
	qh.push(make_pair(a, b));
	while (!qh.empty())
	{
		int x = qh.front().first;
		int y = qh.front().second;
		qh.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << run[x][y] + 1 << "\n";
				return;
			}
			if (building[nx][ny] == '#' || run[nx][ny] != -1) continue;
			if (fire[nx][ny] == -1) {
				run[nx][ny] = run[x][y] + 1;
				qh.push(make_pair(nx, ny));
			}
			else if (fire[nx][ny] > run[x][y] + 1) {
				run[nx][ny] = run[x][y] + 1;
				qh.push(make_pair(nx, ny));
			}
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int t;
	cin >> t;
	int hx, hy;
	while(t--)
	{
		int w, h;
		queue<pair<int, int>> q;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> building[i][j];
				if (building[i][j] == '@') {
					hx = i; hy = j;
				}
				if (building[i][j] == '*')
					q.push(make_pair(i, j));
			}
		}
		bfs_fire(q,h,w);
		bfs_human(hx,hy,h,w);
	}
}