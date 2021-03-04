//1,2,3 더하기 1&4 문제 2개를 동시에 나타내었다.
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int dp[10001];
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int ott[3] = { 1,2,3 };
	cin >> n;	
	dp[0] = 1;/*
	//1,2,3 더하기 1의 경우
	while (n--) {
		cin >> m;
		for (int i = 1; i <= m; i++) {
			if (dp[i]) continue;
			for (int j = 0; j < 3; j++) {				
				if (i - ott[j] >= 0)
					dp[i] += dp[i - ott[j]];
			}
		}
		cout << dp[m] << '\n';
	}*/
	//1,2,3 더하기 4의 경우
	for (int j = 0; j < 3; j++) {
		for (int i = 1; i <= 10000; i++) {
			if (i - ott[j] >= 0)
				dp[i] += dp[i - ott[j]];
		}
	}
	while (n--) {
		cin >> m;		
		cout << dp[m] << '\n';
	}
}