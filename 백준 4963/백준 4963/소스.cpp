#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int check[50][50];
int w, h;
int dx[8] = {0,0,-1,1,-1,-1,1,1};
int dy[8] = {-1,1,0,0,-1,1,-1,1};

void init()
{
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = 0;
			check[i][j] = 0;
		}
	}
}

void bfs(int a, int b)
{
	queue<int> qx; queue<int> qy;
	qx.push(a); qy.push(b);
	int ox, oy, nx, ny;
	while(!qx.empty() && !qy.empty()) {
		ox = qx.front(); oy = qy.front();
		qx.pop(); qy.pop();
		for (int i = 0; i < 8; i++) {
			nx = ox + dx[i];
			ny = oy + dy[i];

			if (nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] == 1 && check[nx][ny] == 0) {
				qx.push(nx); qy.push(ny);
				check[nx][ny] = 1;
			}
		}
	}
}

int main()
{
	while(1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		int landcount = 0;
		init();
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && check[i][j] == 0) {
					landcount++;
					bfs(i,j);
				}
			}
		}
		cout << landcount << "\n";
	}
}