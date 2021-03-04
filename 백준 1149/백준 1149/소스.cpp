#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int a[1000][3], dp[1000][3];

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			cin >> a[i][j];
	for (j = 0; j < 3; j++)
		dp[0][j] = a[0][j];
	for (i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
	}
	cout << min( { dp[n - 1][0],dp[n - 1][1],dp[n - 1][2] } ) << "\n";
}