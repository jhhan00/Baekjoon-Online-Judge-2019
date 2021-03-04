#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int sheep = 0;
int wolf = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char mp[250][250];
bool visit[250][250];
void bfs(int a, int b, int r, int c)
{
	visit[a][b] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	int w = 0, s = 0;
	if (mp[a][b] == 'v') w++;
	else if (mp[a][b] == 'o') s++;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (mp[nx][ny] == '#' || visit[nx][ny]) continue;
			visit[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (mp[nx][ny] == 'v') w++;
			else if (mp[nx][ny] == 'o') s++;
		}
	}
	if (s > w) sheep += s;
	else wolf += w;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> mp[i][j];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((mp[i][j] == 'v' || mp[i][j] == 'o') && visit[i][j] == false)
				bfs(i, j, r, c);
		}
	}
	cout << sheep << ' ' << wolf << endl;
}