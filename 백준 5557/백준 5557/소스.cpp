#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

long long dp[101][21]; // dp[i][j] : i번째 수까지 계산했을 때 j가 나오는 경우의 수
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	int nn[101];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> nn[i];
	dp[1][nn[1]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < 21; j++) {
			if (j - nn[i] >= 0)
				dp[i][j] += dp[i - 1][j - nn[i]];
			if (j + nn[i] < 21)
				dp[i][j] += dp[i - 1][j + nn[i]];
		}
	}
	cout << dp[n - 1][nn[n]] << '\n';
}