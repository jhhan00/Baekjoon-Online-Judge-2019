#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int a[1001];
int dp[1001];
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = -1;
	}
	dp[1] = 1;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == 0) continue;
		if (dp[i] == -1) continue;
		for (int j = 1; j <= a[i] && i+j <= n; j++) {
			if (dp[i+j] == -1 || dp[i+j] > dp[i] + 1)
				dp[i+j] = dp[i] + 1;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dp[i] << ' ';
	cout << endl;
	if (dp[n] == -1)
		cout << -1 << endl;
	else
		cout << dp[n] - 1 << endl;
}