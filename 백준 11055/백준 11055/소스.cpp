#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int a[1001], dp[1001];

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i, j, mx = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];

	dp[1] = a[1];
	for (i = 2; i <= n; i++) {
		dp[i] = a[i];
		for (j = 1; j < i; j++) {
			if (a[i] > a[j] && dp[i] < dp[j] + a[i])
				dp[i] = dp[j] + a[i];
		}
	}
	for (i = 1; i <= n; i++)
		if (dp[i] > mx)
			mx = dp[i];
	cout << mx << "\n";
}