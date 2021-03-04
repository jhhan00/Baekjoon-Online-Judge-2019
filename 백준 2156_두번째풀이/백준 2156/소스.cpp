#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i;
	int drink[10001];
	int dp[10001];
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> drink[i];
	for (i = 1; i <= n; i++) {
		if (i == 1)
			dp[i] = drink[i];
		else if (i == 2)
			dp[i] = drink[i] + drink[i - 1];
		else if (i == 3)
			dp[i] = max(drink[i - 1], drink[i - 2]) + drink[i];
		else
			dp[i] = max(dp[i - 2], drink[i - 1] + dp[i - 3]) + drink[i];
		if (i > 1 && dp[i] < dp[i - 1])
			dp[i] = dp[i - 1];
	}
	cout << dp[n] << "\n";
}