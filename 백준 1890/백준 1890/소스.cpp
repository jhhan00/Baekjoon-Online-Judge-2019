#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int mp[100][100];
long long dp[100][100];
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mp[i][j];
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1 || mp[i][j] == 0) continue;
			int move = mp[i][j];
			if (j + move < n) {
				dp[i][j + move] += dp[i][j];
			}
			if (i + move < n) {
				dp[i + move][j] += dp[i][j];
			}
		}
	}
	cout << dp[n - 1][n - 1] << "\n";
}