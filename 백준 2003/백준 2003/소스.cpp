#pragma warning(disable : 4996)
#include <iostream>
using namespace std;/*
// O(N^2)의 시간복잡도를 가지는 코딩방법
int a[10000];

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, i, j;
	int sum, ans;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> a[i];
	ans = 0;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = i; j < n; j++) {
			sum += a[j];
			if (sum == m)
				ans++;
		}
	}
	cout << ans << "\n";
}*/
//O(N)의 시간 복잡도인 코딩 방법
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, ll, rr, sum;
	cin >> n >> m;
	int b[10000];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	ll = rr = 0;
	sum = b[0];
	int ans = 0;
	while (ll <= rr && rr < n) {
		if (sum < m) {
			rr++;
			sum += b[rr];
		}
		else if (sum > m && ll == rr) {
			ll++; rr++;
			sum = b[ll];
		}
		else if (sum > m) {
			sum -= b[ll];
			ll++;
		}
		else if (sum == m) {
			ans++;
			rr++;
			sum += b[rr];
		}
	}
	cout << ans << "\n";
}