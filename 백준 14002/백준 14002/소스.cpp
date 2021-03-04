#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int aa[1000];
int dp[1000];
int from[1000];

void print(int w)
{
	if (from[w] != -1)
		print(from[w]);
	cout << aa[w] << ' ';
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, i, j, last;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> aa[i];
	dp[0] = 1; from[0] = -1;
	int mx = 0;
	for (i = 1; i < n; i++) {
		dp[i] = 1;
		from[i] = -1;
		for (j = 0; j < i; j++) {
			if (aa[i] > aa[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				from[i] = j;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (mx < dp[i]) {
			mx = dp[i];
			last = i;
		}
	}
	cout << mx << "\n";
	print(last);
}