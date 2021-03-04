#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

char gr[100][100];
bool visit[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void findbfs(int q, int a, int b)
{
	visit[a][b] = true;
	queue<int> qx; queue<int> qy;
	qx.push(a); qy.push(b);
	while (!qx.empty() && !qy.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < q && ny >= 0 && ny < q && gr[nx][ny] == gr[a][b] && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				qx.push(nx);
				qy.push(ny);
			}
		}
	}
}

void rgbfs(int q, int a, int b)
{
	visit[a][b] = true;
	queue<int> qx; queue<int> qy;
	qx.push(a); qy.push(b);
	while (!qx.empty() && !qy.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < q && ny >= 0 && ny < q && visit[nx][ny] == false && (gr[nx][ny]=='R' || gr[nx][ny]=='G')) {
				visit[nx][ny] = true;
				qx.push(nx);
				qy.push(ny);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n,i,j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> gr[i][j];

	int nom = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				nom++;
				findbfs(n, i, j);
			}
		}
	}
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			visit[i][j] = false;
	int abn = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				abn++;
				if (gr[i][j] == 'B')
					findbfs(n, i, j);
				else
					rgbfs(n, i, j);
			}
		}
	}
	cout << nom << ' ' << abn << endl;
}