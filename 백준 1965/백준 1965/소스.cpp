#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int box[1001], dp[1001];
int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	int t, i, j;
	cin >> t;
	for (i = 0; i < t; i++)
		cin >> box[i];
	dp[0] = 1;
	int mx = 1;
	for (i = 1; i < t; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (box[i] > box[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		mx = max(mx, dp[i]);
	}
	cout << mx << "\n";
}