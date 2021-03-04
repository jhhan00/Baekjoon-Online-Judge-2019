#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool ap[1001][1001];
int visit[1001];
int solve(int n, int a)
{
	visit[a] = 0;
	queue<int> q;
	q.push(a);
	int mx = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (ap[x][i] == 1 && visit[i] == -1) {
				visit[i] = visit[x] + 1;
				q.push(i);
				mx++;
			}
		}
	}
	return mx;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		memset(ap, false, sizeof(ap));
		memset(visit, -1, sizeof(visit));
		int n, m;
		cin >> n >> m;
		for (int i = 0; i<m; i++) {
			int a, b;
			cin >> a >> b;
			ap[a][b] = ap[b][a] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (ap[i][j] == 1 && visit[i] == -1) {
					int tmp = solve(n,i);
					ans += tmp;
				}
			}
		}
		cout << ans << '\n';
	}
}