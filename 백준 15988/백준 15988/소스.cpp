#pragma warning(disable : 4996)
#include <iostream>
#define MAX 1000001
#define MOD 1000000009
using namespace std;

long long dp[MAX];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < MAX; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[i] %= MOD;
	}
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		cout << dp[m] << "\n";
	}
}