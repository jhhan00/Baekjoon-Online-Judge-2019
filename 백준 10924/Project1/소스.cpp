#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
using namespace std;

int seq[2001];
int dp[2001][2001];
bool solve(int x, int y)
{
	if (x == y)
		return true;
	else if (x+1 == y) {
		if (seq[x] == seq[y])
			return true;
		else
			return false;
	}

	if (dp[x][y] >= 0) return dp[x][y];
	
	if (seq[x] != seq[y])
		return dp[x][y]=0;
	else
		return dp[x][y] = solve(x + 1, y - 1);
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> seq[i];
	cin >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		dp[i][i] = 1;
	for (int i = 1; i < n; i++) {
		if (seq[i] == seq[i + 1])
			dp[i][i + 1] = 1;
		else
			dp[i][i + 1] = 0;
	}
	for (int k = 3; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
			if (seq[i] == seq[j] && dp[i + 1][j - 1])
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
}