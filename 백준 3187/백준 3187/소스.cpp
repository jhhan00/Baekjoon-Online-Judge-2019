#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

char mp[250][250];
bool vs[250][250];
int wolf = 0, sheep = 0;
void bfs(int a, int b, int r, int c)
{
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	vs[a][b] = true;
	int vw = 0, ks = 0;
	if (mp[a][b] == 'v') vw++;
	if (mp[a][b] == 'k') ks++;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (mp[nx][ny] == '#' || vs[nx][ny]) continue;
			q.push(make_pair(nx, ny));
			vs[nx][ny] = true;
			if (mp[nx][ny] == 'k') ks++;
			if (mp[nx][ny] == 'v') vw++;
		}
	}
	if (ks > vw) sheep += ks;
	else wolf += vw;
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
			if (mp[i][j] != '#' && !vs[i][j]) {
				bfs(i, j, r, c);
			}
		}
	}
	cout << sheep << ' ' << wolf << endl;
}