#pragma warning(disable : 4996)
#include <iostream>
#define MOD 9901
using namespace std;

int dp[100001][3];

int main()
{
	int n, i;
	dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;
	for (i = 2; i < 100001; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]; dp[i][0] %= MOD;
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2]; dp[i][1] %= MOD;
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1]; dp[i][2] %= MOD;
	}
	cin >> n;
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << "\n";
}