#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int card[1001];
	int dp[1001];
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &card[i]);
	dp[1] = card[1];
	for (i = 2; i <= n; i++) {
		dp[i] = card[i];
		for (j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + card[j]);
	}
	printf("%d\n", dp[n]);
}