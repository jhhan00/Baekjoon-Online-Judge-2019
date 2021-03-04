#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long dp[101];
	dp[0] = 0; dp[1] = 1; dp[2] = 2;
	if (n < 3) {
		cout << dp[n] << '\n';
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int k = 1; k <= i - 3; k++) {
			dp[i] = max( dp[i], dp[i-k-2] * (k+1) );
		}
	}
	cout << dp[n] << '\n';
}