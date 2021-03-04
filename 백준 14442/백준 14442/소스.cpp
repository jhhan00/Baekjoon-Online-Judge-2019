#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <queue>
#define MM 1000*1000+1
using namespace std;

int n, m, l;
int mp[1000][1000];
int vs[1000][1000][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void bfs();
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> l;
	string lll[1000];
	for (int i = 0; i < n; i++) {
		cin >> lll[i];
		for (int j = 0; j < m; j++)
			mp[i][j] = lll[i][j] - '0';
	}
	bfs();
	int mini = MM;
	for (int i = 0; i <= l; i++)
		if (vs[n - 1][m - 1][i] != 0 && mini > vs[n - 1][m - 1][i])
			mini = vs[n - 1][m - 1][i];
	
	if (mini == MM)
		cout << -1 << endl;
	else
		cout << mini << endl;
}
void bfs()
{
	vs[0][0][0] = 1;
	queue<int> qx; queue<int> qy; queue<int> qz;
	qx.push(0); qy.push(0); qz.push(0);
	while (!qx.empty() && !qy.empty() && !qz.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		int z = qz.front(); qz.pop();		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (mp[nx][ny] == 0 && vs[nx][ny][z] == 0) {
					vs[nx][ny][z] = vs[x][y][z] + 1;
					qx.push(nx); qy.push(ny); qz.push(z);
				}
				if (mp[nx][ny] == 1 && z + 1 <= l && vs[nx][ny][z + 1] == 0) {
					vs[nx][ny][z + 1] = vs[x][y][z] + 1;
					qx.push(nx); qy.push(ny); qz.push(z + 1);
				}
			}
		}
	}
}