#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, i, j;
	cin >> n;
	int dp[12];
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (i = 4; i < 12; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	for (i = 0; i < n; i++) {
		cin >> j;
		cout << dp[j] << "\n";
	}
}