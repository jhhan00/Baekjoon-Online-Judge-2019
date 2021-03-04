#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int arr[11];
bool check[11];
int solve(int count, int n)
{
	if (n - count == 2) return 0;
	int mx = 0;
	for (int i = 2; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		int left = i - 1;
		int right = i + 1;
		while (check[left]) left--;
		while (check[right]) right++;
		int tmp = arr[left] * arr[right];
		tmp += solve(count + 1, n);
		if (mx < tmp) mx = tmp;
		check[i] = false;
	}
	return mx;
}
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int a = solve(0, n);
	cout << a << ' ';
}