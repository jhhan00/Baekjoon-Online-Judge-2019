#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int nn, dx, dy, sx, sy;
int chess[300][300];
int visit[300][300];
int mx[8] = {-2,-1,2,1,-2,-1,2,1};
int my[8] = {-1,-2,-1,-2,1,2,1,2};

void init()
{
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			chess[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

void bfs() 
{
	int a, b, na, nb;
	queue<int> qx; queue<int> qy;
	chess[sx][sy] = 1;
	visit[sx][sy] = 0;
	qx.push(sx); qy.push(sy);
	while (!qx.empty() && !qy.empty()) {
		a = qx.front(); qx.pop();
		b = qy.front(); qy.pop();
		if (a == dx && b == dy) break;
		for (int i = 0; i < 8; i++) {
			na = a + mx[i];
			nb = b + my[i];
			if (na >= 0 && na < nn && nb >= 0 && nb < nn && chess[na][nb] == 0) {
				chess[na][nb] = 1;
				visit[na][nb] = visit[a][b] + 1;
				qx.push(na); qy.push(nb);
			}
		}
	}
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	for (int s = 0; s < t; s++) {
		cin >> nn;
		init();
		cin >> sx >> sy >> dx >> dy;
		bfs();
		cout << visit[dx][dy] << "\n";
	}
}