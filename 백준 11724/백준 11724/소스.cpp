#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int gr[1001][1001];
bool visit[1001];

void dfs(int q, int n)
{
	visit[q] = true;
	for (int j = 1; j <= n; j++) {
		if (gr[q][j] == 1 && visit[j] == false)
			dfs(j, n);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		gr[a][b] = 1;
		gr[b][a] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			ans++;
			dfs(i, n);
		}
	}
	cout << ans << "\n";
}