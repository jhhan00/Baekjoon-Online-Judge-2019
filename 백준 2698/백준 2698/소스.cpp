#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int dp[101][101][2];
// dp[a][b][z]=c :: a�ڸ��̰� ������Ʈ���� b��, �� ���ڸ��� z(0 or 1)�϶� ����c�� ���´�

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t,n,k;
	cin >> t;
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (j == 0) {
				dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
				dp[i][j][1] = dp[i - 1][j][0];
			}
			else {
				dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
				dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
			}
		}
	}
	while (t--) {
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << endl;
	}
}