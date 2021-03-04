#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int mp[1001][1001];
int vs[1001][1001][2];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void bfs(int a, int b)
{
	vs[1][1][0] = 1;
	queue<int> qx; queue<int> qy; queue<int> qc;
	qx.push(1); qy.push(1); qc.push(0);
	while (!qx.empty() && !qy.empty() && !qc.empty()) {
		int ox = qx.front(); qx.pop();
		int oy = qy.front(); qy.pop();
		int oc = qc.front(); qc.pop();
		if (ox == a && oy == b)
			return;
		for (int i = 0; i < 4; i++) {
			int nx = ox + dx[i];
			int ny = oy + dy[i];
			if (nx > 0 && nx <= a && ny > 0 && ny <= b) {
				if (mp[nx][ny] == 0 && vs[nx][ny][oc] == 0) {
					vs[nx][ny][oc] = vs[ox][oy][oc] + 1;
					qx.push(nx); qy.push(ny); qc.push(oc);
				}
				if (mp[nx][ny] == 1 && oc==0 && vs[nx][ny][oc + 1] == 0) {
					vs[nx][ny][oc + 1] = vs[ox][oy][oc] + 1;
					qx.push(nx); qy.push(ny); qc.push(oc + 1);
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string asdf[1001];
	for (int i = 1; i <= n; i++)
		cin >> asdf[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			mp[i][j+1] = asdf[i][j] - '0';
	bfs(n,m);
	if (vs[n][m][0] != 0 && vs[n][m][1] != 0)
		cout << min(vs[n][m][0], vs[n][m][1]);
	else if (vs[n][m][0] != 0)
		cout << vs[n][m][0];
	else if (vs[n][m][1] != 0)
		cout << vs[n][m][1];
	else
		cout << -1;
	cout << '\n';
}