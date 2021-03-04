#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

struct shark {
	int x, y;
	int s, d, z;
};
bool room[101][101];
int sharksize[101][101];
shark sh[10000];
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int R, C, M;
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		room[r][c] = 1;
		sharksize[r][c] = z;
		sh[i].x = r; sh[i].y = c;
		sh[i].s = s; sh[i].d = d; sh[i].z = z;
	}
	int ans = 0; // 상어의 크기의 합, 최종결과물
	for (int a = 1; a <= C; a++)
	{
		int tx=-1, ty=-1;
		for (int b = 1; b <= R; b++) {
			if (room[b][a] == 1) {
				tx = b; ty = a;
				room[b][a] = 0;
				ans += sharksize[b][a];
				sharksize[b][a] = 0;
				break;
			}
		}
		for (int i = 0; i < M; i++) {
			int ox = sh[i].x;
			int oy = sh[i].y;
			if (ox == tx && oy == ty) { 
				sharksize[sh[i].x][sh[i].y] = 0;
				sh[i].x = 0; sh[i].y = 0;
				continue;
			}
			if (sh[i].x == 0 && sh[i].y == 0) continue;
			if (sharksize[sh[i].x][sh[i].y] != sh[i].z) { 
				sh[i].x = 0; sh[i].y = 0;
				continue;
			}
			room[sh[i].x][sh[i].y] = 0;
			sharksize[sh[i].x][sh[i].y] = 0;
			for (int q = 0; q < sh[i].s; q++) {
				if (sh[i].d == 2 && sh[i].x == R)
					sh[i].d = 1;
				if (sh[i].d == 1 && sh[i].x == 1)
					sh[i].d = 2;
				if (sh[i].d == 3 && sh[i].y == C)
					sh[i].d = 4;
				if (sh[i].d == 4 && sh[i].y == 1)
					sh[i].d = 3;
				sh[i].x = sh[i].x + dx[sh[i].d];
				sh[i].y = sh[i].y + dy[sh[i].d];
			}
		}
		for (int i = 0; i < M; i++) {
			if (room[sh[i].x][sh[i].y] == 0) {
				room[sh[i].x][sh[i].y] = 1;
				sharksize[sh[i].x][sh[i].y] = sh[i].z;
			}
			else {
				if (sharksize[sh[i].x][sh[i].y] < sh[i].z)
					sharksize[sh[i].x][sh[i].y] = sh[i].z;
			}
		}
	}
	cout << ans << "\n";
}