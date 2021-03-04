#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

long long dp[31];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 1; dp[1] = 0; dp[2] = 3;
	for (int i = 3; i < 31; i++) {
		dp[i] = 3 * dp[i - 2];
		int j = i - 2;
		while (j - 2 >= 0) {
			dp[i] += 2 * dp[j - 2];
			j = j - 2;
		}
	}
	cout << dp[n];
}