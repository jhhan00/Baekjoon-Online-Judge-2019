#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int card[3][100001];
long long dp[3][100001];

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, i, t, j, k;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> t;
		for (j = 1; j < 3; j++)
			for (k = 1; k <= t; k++)
				cin >> card[j][k];
		dp[0][1] = 0; dp[1][1] = card[1][1]; dp[2][1] = card[2][1];
		for (k = 2; k <= t; k++) {
			dp[0][k] = max(max(dp[0][k - 1], dp[1][k - 1]), dp[2][k - 1]);
			dp[1][k] = max(dp[0][k - 1], dp[2][k - 1]) + card[1][k];
			dp[2][k] = max(dp[0][k - 1], dp[1][k - 1]) + card[2][k];
		}
		cout << max(max(dp[0][t], dp[1][t]), dp[2][t]) << "\n";
	}
}