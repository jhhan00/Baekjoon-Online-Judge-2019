#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int play[101];
bool dp[101][1001];
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s, m;
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
		cin >> play[i];
	dp[0][s] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j]) {
				if (j + play[i+1] <= m)
					dp[i + 1][j + play[i+1]] = 1;
				if (j - play[i+1] >= 0)
					dp[i + 1][j - play[i+1]] = 1;
			}
		}
	}
	int ans = -1;
	for (int j = 0; j <= m; j++) {
		if (dp[n][j])
			ans = j;
	}
	cout << ans << endl;
}