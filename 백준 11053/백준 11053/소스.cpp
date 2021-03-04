#pragma warning(disable : 4996)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int A[1000];
	int dp[1000];
	int n, i, j, mx;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> A[i];
	dp[0] = 1;
	mx = 1;
	for (i = 1; i < n; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[i], dp[j] + 1); // 여기 생각하는게 핵심
			}
		}
		mx = max(mx, dp[i]);
	}
	cout << mx << "\n";	
}