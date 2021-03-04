//이 문제는 BFS를 적용하는것처럼 보이지만 실제로는 DFS를 적용하는 문제이다.
#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int namu[500][500];
int eat[500][500];
int n;

int pd(int a, int b)
{
	int rt = eat[a][b];
	if (rt != 0)
		return rt;
	rt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny<n && namu[nx][ny]>namu[a][b]) {
			rt = max(rt, pd(nx, ny) + 1);
		}
	}
	return rt;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &namu[i][j]);

	int mx = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			mx = max(mx, pd(i, j));
		}
	}
	printf("%d\n", mx);
}