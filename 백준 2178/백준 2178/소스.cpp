#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#pragma warning(disable : 4996)
#define MAX 101
using namespace std;

int miro[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void BFSmiro(int n, int m)
{
	int nowX, nowY;
	visited[1][1] = 1;
	queue<int> qx; queue<int> qy;
	qx.push(1); qy.push(1);
	while (!qx.empty() && !qy.empty())
	{
		nowX = qx.front(); nowY = qy.front();
		qx.pop(); qy.pop();
		if (nowX == n && nowY == m) 
		{ 
			cout << visited[n][m] << endl; 
			break; 
		}
		for (int i = 0; i < 4; i++)
		{
			int newX = nowX + dx[i];
			int newY = nowY + dy[i];

			if (newX >= 1 && newX <= n && newY >= 1 && newY <= m && miro[newX][newY] == 1 && visited[newX][newY] == 0)
			{
				visited[newX][newY] = visited[nowX][nowY] + 1;
				qx.push(newX); qy.push(newY);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	string line;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			miro[i][j + 1] = line[j] - '0';
		}
	}
	
	BFSmiro(n, m);
}