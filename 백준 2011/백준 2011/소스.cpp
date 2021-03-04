#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#define DVI 1000000
using namespace std;

int dp[5005]; // dp[a]=b => a번째까지 나올 수 있는 암호의 개수가 b
int a[5005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int sz = s.size();
	for (int i = 1; i <= sz; i++)
		a[i] = s[i-1] - '0';
	dp[0] = 1;
	if (a[1] == 0) dp[1] = 0;
	else dp[1] = 1;
	for (int i = 2; i <= sz; i++) {
		if (a[i] >= 1 && a[i] <= 9) {
			dp[i] += dp[i - 1];
			dp[i] %= DVI;
		}
		int tmp = a[i - 1]*10 + a[i];
		if (tmp >= 10 && tmp <= 26) {
			dp[i] += dp[i - 2];
			dp[i] %= DVI;
		}
	}
	for (int i = 1; i <= sz; i++)
		cout << dp[i] << ' ';
	cout << dp[sz];
}