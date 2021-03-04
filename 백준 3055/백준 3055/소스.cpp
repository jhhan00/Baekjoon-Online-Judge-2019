#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

char mp[50][50];
int water[50][50];
int gosm[50][50];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void bfs(int a1, int a2, int b1, int b2)
{
	gosm[a1][a2] = 0;
	queue<int> qx; queue<int> qy;
	qx.push(a1); qy.push(a2);
	while (!qx.empty() && !qy.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < b1 && ny >= 0 && ny < b2) {
				if (mp[nx][ny] == 'X') continue;
				if (gosm[nx][ny] != -1) continue;
				if (water[nx][ny] == -1 || water[nx][ny] > gosm[x][y] + 1) { // 이렇게 조건문을 걸어야 맞았다... 그 이유는 모름
					gosm[nx][ny] = gosm[x][y] + 1;
					qx.push(nx); qy.push(ny);
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
	int r, c, i, j;
	cin >> r >> c;
	queue<int> wqx; queue<int> wqy;
	int s1, s2; // 고슴도치 위치
	int d1, d2; // 도착지점
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			water[i][j] = -1;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == '*') {
				water[i][j] = 0;
				wqx.push(i);
				wqy.push(j);
			}
			else if (mp[i][j] == 'S') {
				s1 = i;
				s2 = j;
			}
			else if (mp[i][j] == 'D') {
				d1 = i;
				d2 = j;
			}
		}
	}
	while (!wqx.empty() && !wqy.empty()) {
		int ox = wqx.front(); wqx.pop();
		int oy = wqy.front(); wqy.pop();
		for (i = 0; i < 4; i++) {
			int nx = ox + dx[i];
			int ny = oy + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (mp[nx][ny] == 'D' || mp[nx][ny] == 'X') continue;
				if (water[nx][ny] == -1) {
					water[nx][ny] = water[ox][oy] + 1;
					wqx.push(nx); wqy.push(ny);
				}
			}
		}
	}
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			gosm[i][j] = -1;

	bfs(s1, s2, r, c);
	if (gosm[d1][d2] == -1)
		cout << "KAKTUS" << '\n';
	else
		cout << gosm[d1][d2] << '\n';
}