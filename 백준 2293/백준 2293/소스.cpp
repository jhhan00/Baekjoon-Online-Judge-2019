#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int coin[101];
int dp[10001];
int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int n, k, i, j;
	cin >> n >> k;
	for (i = 1; i <= n; i++)
		cin >> coin[i];
	dp[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if (j >= coin[i])
				dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k] << "\n";
}