#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int t, i, j;
	int cd[1001], dp[1001];
	cin >> t;
	for (i = 1; i <= t; i++)
		cin >> cd[i];
	dp[0] = 0;
	for (i = 1; i <= t; i++) {
		dp[i] = cd[i];
		for (j = 1; j <= i; j++)
			dp[i] = min(dp[i], dp[i - j] + cd[j]);
	}
	cout << dp[t] << "\n";
}
