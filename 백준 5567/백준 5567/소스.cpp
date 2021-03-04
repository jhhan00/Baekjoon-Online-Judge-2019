#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int fr[501][501];
bool invite[501];
int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int n, m, i, j;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		fr[a][b] = 1; fr[b][a] = 1;
	}
	for (i = 1; i <= n; i++) {
		if (fr[1][i] || fr[i][1]) { // 1狼 模备牢 版快
			for (j = 1; j <= n; j++) {
				if (fr[i][j] || fr[j][i]) { // 1狼 模备狼 模备牢 版快
					invite[i] = true;
					invite[j] = true;
				} // 1狼 模备客 1狼 模备狼 模备老 锭 true肺 秦霖促
			}
		}
	}
	int res = 0;
	for (i = 2; i <= n; i++)
		if (invite[i])
			res++;
	cout << res << '\n';
}