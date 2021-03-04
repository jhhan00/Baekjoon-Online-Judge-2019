#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

long long simsa[100000];
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m, mx=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> simsa[i];
		if (mx < simsa[i])
			mx = simsa[i];
	}
	long long left = 0, right = mx * m, mid;
	long long ans = mx * m;
	while (left <= right) {
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
			sum += mid / simsa[i];
		if (sum >= m) {
			if (ans > mid)
				ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
}