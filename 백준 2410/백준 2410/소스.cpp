#pragma warning(disable : 4996)
#include <iostream>
#define MDO 1000000000
using namespace std;

long long dp[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 0; (1 << i) <= n; i++) {
		for (int j = (1 << i); j <= n; j++) {
			dp[j] += dp[j - (1 << i)];
			dp[j] %= MDO;
			//cout << j << ":" << dp[j] << "  ";
		}//cout << endl;
	}
	cout << dp[n] << endl;
}