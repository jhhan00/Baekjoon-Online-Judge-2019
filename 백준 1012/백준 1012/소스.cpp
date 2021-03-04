#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int field[50][50];
int visited[50][50];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int worm;
int n, m;

void init_field()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			field[i][j] = 0;
}
void init_visited()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;
}

void BFS(int x, int y)
{
	int nx, ny;
	visited[x][y] = worm;
	queue<int> qx; queue<int> qy;
	qx.push(x); qy.push(y);
	while (!qx.empty() && !qy.empty()) {
		nx = qx.front(); ny = qy.front();
		qx.pop(); qy.pop();

		for (int i = 0; i < 4; i++) {
			int nwX = nx + dx[i];
			int nwY = ny + dy[i];

			if (nwX >= 0 && nwX < n && nwY >= 0 && nwY < m && field[nwX][nwY] == 1 && visited[nwX][nwY] == 0) {
				visited[nwX][nwY] = worm;
				qx.push(nwX); qy.push(nwY);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T,k,x,y;
	cin >> T;
	for (int i = 0; i < T; i++) 
	{
		worm = 0;
		init_field();
		init_visited();
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> y >> x;
			field[x][y] = 1;
		}/*
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++)
				cout << field[a][b] << " ";
			cout << endl;
		}*/
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				if (field[a][b] == 1 && visited[a][b] == 0) {
					worm++;
					BFS(a,b);
				}
			}
		}
		cout << worm << endl;/*
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++)
				cout << visited[a][b] << " ";
			cout << endl;
		}*/
	}
}