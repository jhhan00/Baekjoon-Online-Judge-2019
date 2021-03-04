#pragma warning(disable : 4996)
#include <iostream>
#define NUM 1001
#define TEM 10
#define DIV 10007
using namespace std;

int dp[NUM][TEM];
int sum[NUM];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i = 0; i < TEM; i++) {
		dp[1][i] = 1;
		sum[1] += dp[1][i];
		sum[1] %= DIV;
	}
	if (n == 1) {
		cout << sum[1] << "\n";
		return 0;
	}
	for (i = 2; i < NUM; i++) {
		for (j = 0; j < TEM; j++) {
			for (k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= DIV;
			}
			sum[i] += dp[i][j];
			sum[i] %= DIV;
		}
	}
	cout << sum[n] << "\n";
}