#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int n, m;
int tomato[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int tomatoBFS()
{
	int nowX, nowY, max=0;
	queue<int> qx; queue<int> qy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 1) {
				visited[i][j] = 1;
				qx.push(i);
				qy.push(j);
			}
		}
	}

	while (!qx.empty() && !qy.empty()) 
	{
		nowX = qx.front(); nowY = qy.front();
		qx.pop(); qy.pop();
		for (int i = 0; i < 4; i++) {
			int newX = nowX + dx[i];
			int newY = nowY + dy[i];

			if (newX >= 0 && newX < n && newY >= 0 && newY < m && tomato[newX][newY] == 0 && visited[newX][newY] == 0) {
				tomato[newX][newY] = 1;
				visited[newX][newY] = visited[nowX][nowY] + 1;
				qx.push(newX); qy.push(newY);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0)
				return -1;
			else if (visited[i][j] > max)
				max = visited[i][j];
		}
	}
	return max - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> tomato[i][j];

	int k = tomatoBFS();
	cout << k << "\n";
}