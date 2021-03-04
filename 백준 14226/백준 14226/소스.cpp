#pragma warning(disable : 4996)
#include <iostream>
#include <queue>
using namespace std;

int prn[1001][1001];
void bfs(int a, int b, int n)
{
	memset(prn, -1, sizeof(prn));
	prn[a][b] = 0;
	queue<int> qs; queue<int> qc;
	qs.push(a); qc.push(b);
	while (!qs.empty() && !qc.empty()) {
		int s = qs.front(); qs.pop();
		int c = qc.front(); qc.pop();
		if (s == n) break;
		if (prn[s][s] == -1) {
			qs.push(s); qc.push(s);
			prn[s][s] = prn[s][c] + 1;
		}
		if (s + c <= 1000 && prn[s + c][c] == -1) {
			qs.push(s + c); qc.push(c);
			prn[s + c][c] = prn[s][c] + 1;
		}
		if (s - 1 >= 0 && prn[s - 1][c] == -1) {
			qs.push(s - 1); qc.push(c);
			prn[s - 1][c] = prn[s][c] + 1;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	bfs(1, 0, n);
	int ans = -1;
	for (int i = 0; i <= n; i++) {
		if (prn[n][i] != -1) {
			if (ans == -1 || ans > prn[n][i])
				ans = prn[n][i];
		}
	}
	cout << ans << endl;
}