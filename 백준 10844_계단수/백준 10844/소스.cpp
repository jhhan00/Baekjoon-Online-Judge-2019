#pragma warning(disable : 4996)
#include <iostream>
#define TEN 10
#define MOD 1000000000
using namespace std;

int dp[101][TEN];
int sum[101];

int main()
{	
	int n, i, j;
	dp[1][0] = 0;
	for (i = 1; i < TEN; i++) {
		dp[1][i] = 1;
		sum[1] += dp[1][i];
	}
	for (i = 2; i < 101; i++) {
		for (j = 0; j < TEN; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= MOD;
			sum[i] += dp[i][j];
			sum[i] %= MOD;
		}
	}
	scanf("%d", &n);
	printf("%d\n", sum[n]);
}