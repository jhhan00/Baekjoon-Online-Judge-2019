#pragma warning(disable : 4996)/**/
#include <iostream>
#define MOD 1000000009
using namespace std;

long long dp[100001][4]; // dp[i][j] : 합이 i, 맨 끝은 j로 끝남

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	cout.tie(NULL);	
	int t, i, n;/*
	for (i = 1; i < 100001; i++) {
		if (i >= 1) {
			dp[i][1] = dp[i - 1][2] + dp[i - 1][3];
			if (i == 1)
				dp[i][1] = 1;
		}
		if (i >= 2) {
			dp[i][2] = dp[i - 2][1] + dp[i - 2][3];
			if (i == 2)
				dp[i][2] = 1;
		}
		if (i >= 3) {
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2];
			if (i == 3)
				dp[i][3] = 1;
		}
		dp[i][1] %= MOD;
		dp[i][2] %= MOD;
		dp[i][3] %= MOD;
	}*/
	dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
	dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
	for (i = 4; i < 100001; i++) {
		dp[i][1] = dp[i - 1][2] + dp[i - 1][3]; dp[i][1] %= MOD;
		dp[i][2] = dp[i - 2][1] + dp[i - 2][3]; dp[i][2] %= MOD;
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2]; dp[i][3] %= MOD;
	}
	
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << "\n";
	}
}