#pragma warning(disable : 4996)
#include <iostream>
#define MOD 1000000000
using namespace std;
/*
int dp[201][201]; //dp[a][b] : a���� ���ؼ� b�� �ǰ��Ѵ�.

int main()
{
	int n, k, i, j;
	cin >> n >> k;
	
	if (k < 2) {
		cout << 1 << "\n";
		return 0;
	}
	dp[0][0] = 1;
	for (i = 1; i <= k; i++) {
		for (j = 0; j <= n; j++) {
			for (int a = 0; a <= j; a++) {
				dp[i][j] += dp[i - 1][j - a];
				dp[i][j] %= MOD;
			}
		}
	}
	for (i = 1; i <= k; i++) {
		for (j = 0; j <= n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << dp[k][n] << "\n";
}*/
int dp[201][201]; // dp[i][j] : ���� i, j�� ����
int main()
{
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1; // 0�� ����µ� 0���� ����
	if (k == 1)
		cout << 1 << endl;
	else {
		for (int j = 1; j <= k; j++) {
			for (int i = 0; i <= n; i++) {
				for (int a = 0; a <= i; a++) {
					dp[i][j] += dp[i - a][j - 1];
					dp[i][j] %= MOD;
				}
			}
		}
		cout << dp[n][k] << "\n";
	}
}