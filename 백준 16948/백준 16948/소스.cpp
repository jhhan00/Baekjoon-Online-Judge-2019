#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

bool chess[200][200];
int visited[200][200];
int dx[6] = { -2,-2,2,2,0,0 };
int dy[6] = { -1,1,-1,1,-2,2 };

int bfs(int x, int y, int a, int b, int qq)
{
	chess[x][y] = true;
	visited[x][y] = 0;
	queue<int> qx; queue<int> qy;
	qx.push(x); qy.push(y);
	while (!qx.empty() && !qy.empty()) {
		int ox = qx.front(); qx.pop();
		int oy = qy.front(); qy.pop();
		if (ox == a && oy == b)
			return visited[a][b];
		for (int i = 0; i < 6; i++) {
			int nx = ox + dx[i];
			int ny = oy + dy[i];
			if (nx >= 0 && nx < qq && ny >= 0 && ny < qq && chess[nx][ny] == false) {
				chess[nx][ny] = true;
				visited[nx][ny] = visited[ox][oy] + 1;
				qx.push(nx); qy.push(ny);
			}
		}
	}
	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int s1, s2, e1, e2; // 시작점, 끝점
	cin >> s1 >> s2 >> e1 >> e2;
	int ans = bfs(s1, s2, e1, e2, n);
	cout << ans << endl;
}