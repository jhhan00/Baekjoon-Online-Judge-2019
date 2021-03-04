#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int chon[101][101];
int su[101];
void dfs(int k, int n)
{
	for (int i = 1; i <= n; i++) {
		if (chon[k][i] == 1 && su[i] == 0) {
			su[i] = su[k] + 1;
			dfs(i, n);
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, m;
	cin >> n;
	cin >> a >> b; // 찾아야 할 촌수
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		chon[x][y] = 1;
		chon[y][x] = 1;
	}
	su[a] = 0;
	dfs(a, n);
	if (su[b] == 0)
		cout << -1 << endl;
	else
		cout << su[b] << endl;
}