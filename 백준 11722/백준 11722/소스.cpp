#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int a[1001], dp[1001];

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int n, i, j;
	cin >> n;
	for (i = n; i > 0; i--)
		cin >> a[i];
	
	dp[1] = 1;
	int mx = dp[1];
	for (i = 2; i <= n; i++) {
		dp[i] = 1;
		for (j = 1; j < i; j++) {
			if (a[i] > a[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		mx = max(mx, dp[i]);
	}
	
	cout << mx << "\n";
}